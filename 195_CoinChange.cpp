#include <iostream>
#include <vector>
using namespace std;

int solveMem(vector<int> &coins, int amount, vector<int> &dp)
{
    if (amount == 0)
    {
        return 0;
    }
    if (amount < 0)
    {
        return -1;
    }
    if (dp[amount] != 0)
    {
        return dp[amount];
    }

    int mini = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        int subproblem = solveMem(coins, amount - coins[i], dp);
        if (subproblem != -1)
        {
            mini = min(mini, 1 + subproblem);
        }
    }

    dp[amount] = (mini == INT_MAX) ? -1 : mini;
    return dp[amount];
}

int solveTab(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < coins.size(); j++)
        {
            if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX)
            {
                int subproblem = dp[i - coins[j]]; 
                dp[i] = min(dp[i], 1 + subproblem);
            }
        }
    }
    return (dp[amount] == INT_MAX) ? -1 : dp[amount]; 
}


int coinChange(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, 0);
    int ans1 = solveMem(coins, amount, dp);

    int ans2 = solveTab(coins,amount);
    return ans2;
}

int main()
{
    // * Coin Change

    // ! You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
    // ! Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
    // ! You may assume that you have an infinite number of each kind of coin.

    vector<int> coins{1, 2, 5};
    int amount = 11;

    int ans = coinChange(coins, amount);
    cout << "Ans is: " << ans << endl;

    return 0;
}