#include <iostream>
#include <vector>
using namespace std;

bool solveUsingRecursion(int index,vector<int>& nums,int target) {
    int n = nums.size();
    if (index>=n)
    {
        return 0;
    }

    if (target<0)
    {
        return 0;
    }

    if (target == 0)    
    {
        return 1;
    }

    bool include = solveUsingRecursion(index+1,nums,target-nums[index]);
    bool exclude = solveUsingRecursion(index+1,nums,target);
    
    return (include || exclude);
}

bool solveUsingMem(int index,vector<int>& nums,int target,vector<vector<int> >&dp) {
    int n = nums.size();
    if (index>=n)
    {
        return 0;
    }

    if (target<0)
    {
        return 0;
    }

    if (target == 0)    
    {
        return 1;
    }

    if(dp[index][target]!=-1){
        return dp[index][target];
    }

    bool include = solveUsingMem(index+1,nums,target-nums[index],dp);
    bool exclude = solveUsingMem(index+1,nums,target,dp);
    
    dp[index][target] = (include || exclude);
    return dp[index][target];
}

 bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        if(sum & 1){
            return false;
        }
        int target = sum/2;
        int index = 0;
        // bool ans = solveUsingRecursion(index,nums,target);

        vector<vector<int> > dp(nums.size(),vector<int>(target+1,-1));
        bool ans = solveUsingMem(index,nums,target,dp);

        return ans;
}

int main()
{
    // * Partition Equal Subset Sum
    // ! Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

    vector<int> nums = {1,5,11,5};
    bool result1 = canPartition(nums);
    cout << "Test Case 1: " << (result1 ? "True" : "False") << endl;

    return 0;
}