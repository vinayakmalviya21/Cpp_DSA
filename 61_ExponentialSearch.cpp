#include<iostream>
#include<vector>
using namespace std; 

// * Exponential Search

// ! Time Complexity = O(2^{(log m)-1})

// ~ Application:-
// ~ 1. Better than Binary Search
// ~ 2. Used in infinite array

int BS(vector<int> &nums,int s,int e,int x){
    while(s<=e){
        int mid = (s+e)/2;
        if(nums[mid] == x){
            cout<<"Found at "<<mid<<endl;
            return mid;
        }
        else if(x>nums[mid]){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    cout<<"Not Found"<<endl;
    return -1;
}

int main(){

    // * Exponential Search

    vector<int> nums {3,4,5,6,11,13,14,15,56,70};
    int x = 56;
    int n = nums.size()-1;
    if(nums[0] == x){
        cout<<"Found at 0"<<endl;
        return 0;
    }
    int i=1;
    while(i<n && nums[i]<= x){
        i=i*2;
    }
    
    return BS(nums,i/2,min(i,n-1),x);

}