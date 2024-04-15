#include <iostream>
#include <vector>
using namespace std;

int solveUsingRecursion(string &a, string &b, int i, int j)
{
    if (i == a.length() || j == b.length())
    {
        return 0;
    }
    if (a[i] == b[j])
    {
        return 1 + solveUsingRecursion(a, b, i + 1, j + 1);
    }
    else
    {
        return max(solveUsingRecursion(a, b, i, j + 1), solveUsingRecursion(a, b, i + 1, j));
    }
}

int solveUsingMem(string &a, string &b, int i, int j, vector<vector<int>> &dp)
{
    if (i == a.length() || j == b.length())
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (a[i] == b[j])
    {
        return dp[i][j] = 1 + solveUsingMem(a, b, i + 1, j + 1, dp);
    }
    else
    {
        return dp[i][j] = max(solveUsingMem(a, b, i, j + 1, dp), solveUsingMem(a, b, i + 1, j, dp));
    }
}

int longestCommonSubsequence(string text1, string text2)
{
    // Recursive approach
    // return solveUsingRecursion(text1, text2, 0, 0);

    // Memoized approach
    vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
    return solveUsingMem(text1, text2, 0, 0, dp);
}

int main()
{
    // * Longest Commom Subsequence
    // ! Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.
    // ! FA subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
    // ! For example, "ace" is a subsequence of "abcde".
    // ! A common subsequence of two strings is a subsequence that is common to both strings.

    string text1 = "abcde", text2 = "ace";
    int ans = longestCommonSubsequence(text1, text2);
    cout << ans << endl;

    return 0;
}