#include<iostream>
#include<vector>
#include<cmath>
using namespace std; 

int main(){

    // ~ 1. Binary Search in nearly sorted array

    // vector<int> arr{10, 3, 40, 20, 50, 80, 70};
    // int target = 50;
    // int start = 0;
    // int end = arr.size() - 1;

    // while (start <= end) {
    //     int mid = start + (end - start) / 2;

    //     if (arr[mid] == target) {
    //         cout<<mid;
    //         return mid;
    //     }

    //     if (mid - 1 >= start && arr[mid - 1] == target) {
    //         cout<<mid-1;
    //         return mid - 1;
    //     }

    //     if (mid + 1 <= end && arr[mid + 1] == target) {
    //         cout<<mid+1;
    //         return mid + 1;
    //     }

    //     if (target > arr[mid]) {
    //         start = mid + 2;
    //     } else {
    //         end = mid - 2;
    //     }
    // }
    // cout<<-1<<endl;


    // ~ 2. Divide 2 numbers using binary search

    // int dividend = 201;
    // int divisor = -10;
    // int quotient = 0;
    // int s = 0;
    // int e = abs(dividend);
    // int mid;

    // if (divisor == 1)
    //     return dividend;

    // while (s <= e) {
    //     mid = s + (e - s) / 2;

    //     if(abs(mid * divisor) == abs(dividend)){
    //         cout << "Quotient is: " << mid << endl;
    //         return mid;
    //     }

    //     if (abs(mid * divisor) > abs(dividend)){
    //         e = mid - 1;
    //     } 
    //     else {
    //         quotient = mid;
    //         s = mid + 1;
    //     }
    // }
    // if((divisor<0 && dividend<0) || (divisor>0 && dividend>0)){
    //     cout << "Quotient is: " << quotient << endl;
    // }
    // else{
    //     cout<<"Quotient is: " << -1*(quotient) << endl;
    // }


    // ~ 3. Find odd occuring element in an array i.e. all element occur even number of times except one element

    vector<int> arr{1,1,2,2,1};
    int s=0;
    int e=arr.size()-1;
    int mid = s +(e-s)/2;

    while(s<=e){
        if(s==e){
            // ! Single element
            cout<<"Index is at "<<s<<endl;
            cout<<"Value is "<<arr[s]<<endl;
            return s;
        }

        // ! mid -> even or mid-> odd
        if(mid%2 ==0){
            if(arr[mid] == arr[mid+1]){
                s = mid+2;
            }
            else{
                e=mid;
            }
        }

        else{
            if(arr[mid] == arr[mid-1]){
                s = mid+1;
            }
            else{
                e=mid-1;
            }
        }
        mid = s+(e-s)/2;
    }
    cout<<"No odd occuring element"<<-1<<endl;


    return 0;
}

   