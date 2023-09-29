#include<iostream>
#include<vector>
using namespace std; 

int main(){

    // ! Find duplicate number in array

    vector<int> nums = {3,1,3,4,2};

    for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i] == nums[j]){
                    cout<<nums[i];
                }
            }
    }

    return 0;
}