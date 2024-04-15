#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int findMax(vector<int> &arr, int left, int right)
{
    int maxi = 0;
    for (int i = left; i <= right; i++)
    {
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}

int solve(vector<int> &arr, int left, int right, vector<vector<int>> &dp)
{
    if (left == right)
        return 0; // bcz it will be leaf node, and we only need to consider non leaf node
    if (dp[left][right] != -1)
        return dp[left][right];

    int ans = INT_MAX;
    for (int i = left; i < right; i++)
    {
        ans = min(ans, (findMax(arr, left, i) * findMax(arr, i + 1, right)) + (solve(arr, left, i, dp) + solve(arr, i + 1, right, dp)));
    }
    dp[left][right] = ans;
    return dp[left][right];
}

int mctFromLeafValues(vector<int> &arr)
{
     int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    int ans = solve(arr, 0, n - 1, dp);
    return ans;
}

int main()
{
    // * Minimum Cost Tree From Leaf Values
    // ! Given an array arr of positive integers, consider all binary trees such that:
    // ! Each node has either 0 or 2 children;
    // ! The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
    // ! The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.
    // ! Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. It is guaranteed this sum fits into a 32-bit integer.
    // ! A node is a leaf if and only if it has zero children.

    vector<int> arr {6, 2, 4};
    int ans = mctFromLeafValues(arr);
    cout << ans << endl;

    return 0;
}