#include <iostream>
#include <vector>
using namespace std;

int numRollsToTarget(int n, int k, int target) {
    int MOD = 1000000007;
    
    // Initialize dp table
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    
    // Base case: one dice
    for (int j = 1; j <= min(k, target); j++) {
        dp[1][j] = 1;
    }
    
    // Fill dp table
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            for (int x = 1; x <= k && x <= j; x++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - x]) % MOD;
            }
        }
    }
    
    return dp[n][target];
}


int main()
{
    // * Number Of Dice Rolls With Target Sum
    // ! You have n dice, and each dice has k faces numbered from 1 to k.
    // ! Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the dice, so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 10^9 + 7.

    int n = 2; // number of dice
    int k = 6; // number of faces
    int target = 7; // target sum
    
    int ways = numRollsToTarget(n, k, target);
    
    cout << "Number of ways to get target sum: " << ways << endl;

    return 0;
}