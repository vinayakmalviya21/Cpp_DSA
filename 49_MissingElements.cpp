#include<bits/stdc++.h>
using namespace std; 

int main(){

    // ! Find missing elements from an array with duplicates

    // N => Size of array
    // a[i] consist of [1,N]

    vector<int> nums = {1,2,4,3,4};

    sort(nums.begin(),nums.end());

    for(int i=0;i<nums.size();i++){
            if(nums[i] != (i+1)){
                cout<<(i+1);
            }
    }

    return 0;
}