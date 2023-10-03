#include <bits/stdc++.h>
using namespace std;

// * 3. Sorted + Binary Search approach

int bs(vector<int>&nums,int start ,int x){
    int s = 0, e = nums.size()-1;
    while(s<=e){
        int mid = (s+e)/2;
        if(nums[mid] == x){
            return mid;
        }
        else if(x > nums[mid]){
            s = mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return -1;
}


int main()
{

    // ~ K-diff Pairs in an Array

    // ! Conditions
    // ! 0 <= i , j<nums.length
    // ! i != j
    // ! nums[i] - nums[j] == k

    vector<int> nums{3, 1, 4, 1, 5};
    int k;
    cout << "Enter value of k: ";
    cin >> k;

    // * 1. Brute force

    // ! yaha pr unique pair nhi aarha h

    // int count = 0;
    // for(int i=0;i<nums.size();i++){
    //     for(int j=i+1;j<nums.size();j++){
    //         if(abs(nums[i] - nums [j]) == abs(k)){
    //             count++;
    //             cout<<nums[i]<<" , "<<nums[j]<<endl;
    //         }
    //     }
    // }
    // cout << count << endl;


    // * 2. Two pointer approach

    // int i = 0, j = 1;
    // set<pair<int, int>> count;
    // sort(nums.begin(),nums.end());
    // while (j < nums.size())
    // {
    //     int diff = nums[j] - nums[i];
    //     if (diff == k)
    //     {
    //         count.insert({nums[i], nums[j]});
    //         cout<<nums[i]<<" , "<<nums[j]<<endl;
    //         i++, j++;
    //     }
    //     else if (diff > k)
    //     {
    //         i++;
    //     }
    //     else
    //     {
    //         j++;
    //     }
    //     if (i == j)
    //         j++;
    // }
    // cout<<count.size()<<endl;


    // * 3. Sorted + Binary Search approach

    sort(nums.begin(), nums.end());
    set<pair<int, int>> ans;

    for(int i = 0; i < nums.size(); i++) {
        if(bs(nums, i+1, nums[i]+k) != -1){
            ans.insert({nums[i], nums[i] + k});
        }
    }
    cout << ans.size() << endl;
    

    return 0;
}