#include <bits/stdc++.h>
using namespace std;

// int climbStairs(int n){
//     if(n == 0 || n == 1){
//         return 1;
//     }
//     return climbStairs(n-1) + climbStairs(n-2);
// }

// void print(int arr[],int n,int i){
//     if(i>=n){
//         return;
//     }
//     cout<<arr[i]<<" ";
//     print(arr,n,i+1);
// }

// void findMax(int arr[], int n, int i, int& maxi)
// {
//     if (i >= n)
//     {
//         return;
//     }

//     if (arr[i] > maxi)
//     {
//         maxi = arr[i];
//     }
//     findMax(arr, n, i + 1,maxi);
// }

// void findMini(int arr[], int n, int i, int& mini)
// {
//     if (i >= n)
//     {
//         return;
//     }

//     if (arr[i] < mini)
//     {
//         mini = arr[i];
//     }
//     findMini(arr, n, i + 1,mini);
// }

// bool checkKey(string& str,int i,int n,char key){
//     if(i>=n){
//         return false;
//     }
//     if(str[i]==key){
//         return true;
//     }
//     bool ans = checkKey(str,i+1,n,key);
//     return ans;
// }

int main()
{
    // * Recursion - 2

    // ! Staircase problem - steps allowed (1 stair at a time or 2 stairs at a time) , find total no. of ways to reach nth stair

    // ~ let n = 3 then ans = 3 -> ways = (1,1,1) or (1,2) or (2,1)

    // int n;
    // cout<<"Enter value of n"<<endl;
    // cin>>n;

    // int ans = climbStairs(n);
    // cout<<"Answer is : "<<ans<<endl;

    // ! Print an array

    // int arr[5] = {10,20,30,40,50};
    // int n = 5;
    // int i=0;
    // print(arr,n,i);

    // ! Maximum element of array

    // int arr[6] = {10, 20, 30, 60, 40, 50};
    // int n = 6;
    // int i = 0;
    // int maxi = INT_MIN;
    // findMax(arr, n, i, maxi);
    // cout << "Maximum number is: " << maxi << endl;

    // ! Minimum element of array

    // int arr[6] = {10, 20, 30, 60, 40, 5};
    // int n = 6;
    // int i = 0;
    // int mini = INT_MAX;
    // findMini(arr, n, i, mini);
    // cout << "Minimum number is: " << mini << endl;

    // ! Find key in a string

    // string str = "lovebabbar";
    // int n = str.length();
    // char key = 'r';
    // int i=0;

    // bool ans = checkKey(str,i,n,key);

    // cout<<"Answer is: "<<ans;

    


    return 0;
}