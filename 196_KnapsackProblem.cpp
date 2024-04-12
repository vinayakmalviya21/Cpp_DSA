#include <iostream>
#include <vector>
using namespace std;

int solveUsingRecursion(vector<int>& weight, vector<int>& value, int index, int capacity) {
    if (index == 0 || capacity == 0) {
        return 0;
    }

    if (weight[index - 1] > capacity) {
        return solveUsingRecursion(weight, value, index - 1, capacity);
    }

    int include = value[index - 1] + solveUsingRecursion(weight, value, index - 1, capacity - weight[index - 1]);

    int exclude = solveUsingRecursion(weight, value, index - 1, capacity);

    return max(include, exclude);
}

int solveUsingDP(vector<int>& weight, vector<int>& value, int n, int capacity) {
    // Create a 2D array to store the results of subproblems
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Initialize the first row and column to 0 (base case)
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= capacity; ++j) {
        dp[0][j] = 0;
    }

    // Fill the dp table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= capacity; ++j) {
            if (weight[i - 1] <= j) {
                dp[i][j] = max(value[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // Return the result stored in the bottom-right cell of the dp table
    return dp[n][capacity];
}

int main() {
    // * Knapsack Problem

    vector<int> weight = {4, 5, 1};
    vector<int> value = {1, 2, 3};
    int n = 3;
    int capacity = 4;

    // int ans = solveUsingRecursion(weight, value, n, capacity);

    int ans = solveUsingDP(weight, value, n, capacity);
    
    cout << ans << endl;

    return 0;
}
