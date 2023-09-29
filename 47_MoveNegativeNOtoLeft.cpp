#include<iostream>
#include<vector>
using namespace std; 

int main(){

    // ! Move all negative numbers to left side of an array and order maintained not required

    vector<int> nums = {-1,2,-3,4,-5,6,0,-5,34,-7};

    for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]<0){
                    swap(nums[i],nums[j]);
                }
            }
    }

    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }

    return 0;
}