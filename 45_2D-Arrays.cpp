#include<iostream>
#include<limits.h>
#include<vector>
using namespace std; 

int main(){

    // * Initialization
    // int brr [3][3] = {{1,2,3},{4,5,6},{7,8,9}};

    // * Access elements of 2D-array
    // int rows=3;
    // int cols=3;

    // ! Row wise access
    // for(int i=0;i<rows;i++){
    //     for(int j=0;j<cols;j++){
    //         cout<<brr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // ! Column wise access
    // for(int i=0;i<rows;i++){
    //     for(int j=0;j<cols;j++){
    //         cout<<brr[j][i]<<" ";
    //     }
    //     cout<<endl;
    // }

    // * New arrays
    // int arr[4][3];
    // int rows = 4;
    // int cols = 3;

    // ! row wise input
    // for(int i=0;i<rows;i++){
    //     for(int j=0;j<cols;j++){
    //         cin>>arr[i][j];
    //     }
    // }

    // ! column wise input
    // for(int i=0;i<rows;i++){
    //     for(int j=0;j<cols;j++){
    //         cin>>arr[j][i];
    //     }
    // }


    // ~ 1. Row Sum Print

    // int arr[5][4] = {{1,2,3,4},{2,3,4,1},{5,6,1,3},{2,4,6,8},{1,9,9,6}};
    // int rows=5;
    // int cols=4;
    // int sum=0;

    // for(int i=0;i<rows;i++){
    //     for(int j=0;j<cols;j++){
    //         sum+=arr[i][j];
    //     }
    //     cout<<"Sum of "<<i<<"th row is: "<<sum<<endl;
    //     sum = 0;
    // }


    // ~ 2. Column Sum Print

    // int arr[5][4] = {{1,2,3,4},{2,3,4,1},{5,6,1,3},{2,4,6,8},{1,9,9,6}};
    // int rows=5;
    // int cols=4;
    // int sum=0;

    // for(int i=0;i<cols;i++){
    //     for(int j=0;j<rows;j++){
    //         sum+=arr[j][i];
    //     }
    //     cout<<"Sum of "<<i<<"th column is: "<<sum<<endl;
    //     sum = 0;
    // }



    // ~ 3. Linear Search

    // int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    // int rows=3;
    // int cols=3;
    // int key=5;

    // for(int i=0;i<rows;i++){
    //     for(int j=0;j<cols;j++){
    //         if(key == arr[i][j]){
    //             cout<<key<<" is present at "<<i<<"th row and "<<j<<"th column"<<endl;
    //             return 0;
    //         }
    //     }
    // }
    // cout<<key<<" not found"<<endl;


    // ~ 4. Maximum and Minimum element in 2-D array

    // int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    // int rows=3;
    // int cols=3;
    // int mini = INT_MAX;
    // int maxi = INT_MIN;

    // for(int i=0;i<rows;i++){
    //     for(int j=0;j<cols;j++){
    //         if(arr[i][j] < mini){
    //             mini = arr[i][j];
    //         }
            
    //         if(arr[i][j] > maxi){
    //             maxi = arr[i][j];
    //         }
    //     }
    // }
    // cout<<"Minimum: "<<mini<<endl;
    // cout<<"Maximum: "<<maxi<<endl;


    // ~ 5.  Transpose a 2-D array

    // int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    // int rows=3;
    // int cols=3;
    // int transpose[3][3];

    // for(int i=0;i<rows;i++){
    //     for(int j=0;j<cols;j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // for(int i=0;i<rows;i++){
    //     for(int j=0;j<cols;j++){
    //         transpose[j][i] = arr[i][j];
            
    //     }
    // }

    // cout<<"Transpose of matrix"<<endl;
    // for(int i=0;i<rows;i++){
    //     for(int j=0;j<cols;j++){
    //         cout<<transpose[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }


    // * Defining Vector of vector Part - 1

    // vector<vector<int> > arr;

    // vector<int> a{1,2,3};
    // vector<int> b{2,4,6};
    // vector<int> c{1,3,7};

    // arr.push_back(a);
    // arr.push_back(b);
    // arr.push_back(c);

    // for(int i=0;i<arr.size();i++){
    //     for(int j=0;j<arr[i].size();j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }


    // * Defining Vector of vector Part - 2

    vector<vector<int> > arr(2,vector<int>(3,0));

    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[i].size();j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}