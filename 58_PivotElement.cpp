#include<iostream>
#include<vector>
using namespace std; 

int main(){

    // ~ 1. Find pivot element

    vector<int> arr{9,10,2,4,6,8};
    int start = 0;
    int end = arr.size()-1;
    int mid;

    while (start <= end)
    {
        mid = start + (end - start) / 2;

        if(start == end){
            cout<<arr[start]<<endl;
            return 0;
        }

        if (mid+1<=end && arr[mid]>arr[mid+1])
        {
            cout<<arr[mid]<<endl;
            return 0;
        }

        if (mid-1>=start && arr[mid-1]>arr[mid])
        {
            cout<<arr[mid-1]<<endl;
            return 0;
        }

        if(arr[start]>arr[mid]){
            end = mid-1;
        }
        else{
            start=mid+1;
        }
        
    }
    cout<<-1<<endl;

    return 0;
}