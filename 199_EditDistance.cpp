#include <iostream>
#include <vector>
using namespace std;

int solve(string &word1, string &word2, int i, int j, vector<vector<int>> &dp)
{
    if (i == word1.length())
        return word2.length() - j;
    if (j == word2.length())
        return word1.length() - i;
    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;
    if (word1[i] == word2[j])
    {
        ans = 0 + solve(word1, word2, i + 1, j + 1, dp);
    }
    else
    {
        int insertChar = 1 + solve(word1, word2, i, j + 1, dp);
        int deleteChar = 1 + solve(word1, word2, i + 1, j, dp);
        int replaceChar = 1 + solve(word1, word2, i + 1, j + 1, dp);
        ans = min(insertChar, min(deleteChar, replaceChar));
    }
    dp[i][j] = ans;
    return dp[i][j];
}

int minDistance(string word1, string word2)
{
    int i = 0;
    int j = 0;
    vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, -1));
    int ans = solve(word1, word2, i, j, dp);
    return ans;
}

int main()
{
    // * Edit Distance
    // ! Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
    // ! You have the following three operations permitted on a word:
    // ! Insert a character
    // ! Delete a character
    // ! Replace a character

    string word1 = "horse";
    string word2 = "ros";

    int ans = minDistance(word1,word2);
    cout<<ans<<endl;

    return 0;
}