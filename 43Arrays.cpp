#include <iostream>
#include <limits.h>
using namespace std;

int main()
{

// ~ ---------------  #1.Linear Search

    //     int arr[] = {1,2,3,4,5,6,7,8};
    //     int size = 8;

    //     int key = 15;

    //     bool flag = 0;   // 0 -> not found and 1 -> found

    //     for(int i=0;i<size;i++){
    //         if(arr[i] == key){
    // found
    //             flag = 1;
    //             break;
    //         }
    //     }
    //     if(flag)
    //         cout<<"Present"<<endl;
    //     else
    //         cout<<"Not present"<<endl;

// * ---------------------------------------

// ~ ---------- #2.Count number of 0's and 1's

    // int arr[] = {0,0,0,1,1,1,0,1,0,0};
    // int size = 10;

    // int numZero=0;
    // int numOne=0;

    // for(int i=0;i<size;i++){
    //     if(arr[i]==0){
    //         numZero++;
    //     }
    //     else{
    //         numOne++;
    //     }
    // }

    // cout<<"No. of zeroes and ones are: "<<numZero<<" "<<numOne<<endl;

// * ---------------------------------------

// ~ --------- #3.Maximum and Minimum number of Array

    // int arr[] = {2,4,1,6,8,9,0};
    // int size = 7;
    // int maxNum = INT_MIN; // header file <limits.h>
    // int minNum = INT_MAX;

    // for(int i=0;i<size;i++){
    //     if(arr[i]>=maxNum){
    //         maxNum = arr[i];
    //     }

    //     if(arr[i]<=minNum){
    //         minNum = arr[i];
    //     }
    // }
    // cout<<maxNum<<endl;
    // cout<<minNum<<endl;

// * ---------------------------------------

// ~ --------- #4.Extreme Print in Array

    // int arr[] = {1, 2, 3, 4, 5, 6, 7};
    // int size = 7;
    // output -> 1 7 2 6 3 5 4
    // int start = 0;
    // int end = size - 1;
    // while (true)
    // {
    //     if (start > end)
    //         break;

    //     if (start == end)
    //     {
    //         cout << arr[start] << " ";
    //     }
    //     else
    //     {
    //         cout << arr[start] << " ";
    //         cout << arr[end] << " ";
    //     }
    //     start++;
    //     end--;
    // }


// * ---------------------------------------

// ~ --------- #5.Reverse an Array

int arr[] = {1, 2, 3, 4, 5, 6, 7,8};
int size = 8;
int start = 0;
int end = size - 1;
while(start<=end){
    swap(arr[start],arr[end]);
    start++;
    end--;
}
for(int i=0;i<size;i++){
    cout<<arr[i]<<" ";
}

    return 0;
}