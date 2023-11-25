#include <bits/stdc++.h>
using namespace std;

int rob(vector<int>& nums,int i){

    if(i>=nums.size()){
        return 0;
    }

    int robAmt1 = nums[i] + rob(nums,i+2);
    int robAmt2 = 0 + rob(nums,i+1);

    return max(robAmt1,robAmt2);
}

int main()
{
    // * House Robber Problem
    // ! You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

    vector<int> nums{1,2,3,1}; 
    int ans = rob(nums,0);
    cout<<ans;

    return 0;
}