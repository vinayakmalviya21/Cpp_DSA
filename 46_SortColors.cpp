#include<iostream>
#include<vector>
using namespace std; 

int main(){

    // ! Sort Colors or Sort array of 0,1,2

    vector<int> nums = {2,0,2,1,1,0};

    for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]>nums[j]){
                    swap(nums[i],nums[j]);
                }
            }
        }

    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }

    return 0;
}