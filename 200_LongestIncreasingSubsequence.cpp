#include <iostream>
#include <vector>
using namespace std;

int lengthOfLIS(vector<int> &nums)
{
    vector<int> dp(nums.size(), 1);
    int n = dp.size(), maxi2 = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        int maxi = 0;
        for (int j = i + 1; j < n; j++)
            if (nums[i] < nums[j])
                maxi = max(maxi, dp[j]);
        dp[i] = dp[i] + maxi;
        maxi2 = max(maxi2, dp[i]);
    }
    return maxi2;
}

int main()
{
    // * Longest Increasing Subsequence
    // ! Given an integer array nums, return the length of the longest strictly increasing subsequence.

    vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
    int ans = lengthOfLIS(nums);
    cout<<ans<<endl;

    return 0;
}