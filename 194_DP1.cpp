#include <iostream>
#include <vector>
using namespace std;

// * Recursion + Memoization
int topDownSolve(int n, vector<int>& dp) {
    if (n <= 1) return n;

    if (dp[n] != -1) return dp[n];

    dp[n] = topDownSolve(n - 1, dp) + topDownSolve(n - 2, dp);

    return dp[n];
}

int bottomUpSolve(int n) {
    if (n <= 1) return n;

    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {

    // * Dynamic Programming
    // ! Past se sikho i.e. jo ek bar calculate krdo usko store krlo and bhul mt jana

    int n = 5;
    vector<int> dp(n + 1, -1); 
    cout << topDownSolve(n, dp) << endl;

    cout << bottomUpSolve(n) << endl;

    return 0;
}
