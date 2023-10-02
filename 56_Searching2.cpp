#include<iostream>
using namespace std; 

int main() {

    // ~ 1. Find square root

    // int n;
    // cout << "Enter your number: ";
    // cin >> n;
    // int target = n;

    // int s = 0;
    // int e = n;
    // int mid = s + (e - s) / 2;
    // double ans = -1;

    // while (s <= e) {
    //     if ((mid * mid) == target) {
    //         cout << mid << endl;
    //         return mid;
    //     } else if ((mid * mid) > target) {
    //         e = mid - 1;
    //     } else {
    //         ans = mid;
    //         s = mid + 1;
    //     }
    //     mid = s + (e - s) / 2; 
    // }

    // double precision;
    // cout<<"Enter number of floating digits in precision "<<endl;
    // cin>>precision;

    // double step = 0.1;
    // for(int i=0;i<precision;i++){

    //     for(double j=ans;j*j<=n;j=j+step){
    //         ans = j;
    //     }
    //     step = step / 10;
    // }
    // cout<<ans<<endl;


    // * Binary Search 2D Matrix  

    // int arr[5][4] = {{1,2,3,4},
    //                  {5,6,7,8},
    //                  {9,10,11,12},
    //                  {13,14,15,16},
    //                  {17,18,19,20}
    // };
    // int rows = 5;
    // int cols = 4;

    // int target = 22;

    // int ans=-1;

    // int s=0;
    // int e=rows*cols-1;
    // int mid = s + (e-s)/2;

    // while(s<=e){
    //     int rowIndex = mid/cols;
    //     int colIndex = mid%cols;
        
    //     if(arr[rowIndex][colIndex] == target){
    //         cout<<rowIndex<<" , "<<colIndex<<endl;
    //         return 1;
    //     }
        
    //     if(arr[rowIndex][colIndex] < target){
    //         s = mid+1;
    //     }
    //     else{
    //         e = mid-1;
    //     }
    //     mid = s + (e-s)/2;
    // }

    // cout<<ans<<endl;


    return 0;
}

