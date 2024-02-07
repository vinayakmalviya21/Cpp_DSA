#include <bits/stdc++.h>
using namespace std;

int main()
{

    // * Count Inversion
    // ! In an array,arr , the elements at indices i and j  (where i<j ) form an inversion if arr[i] > arr[j]. In other words, inverted elements arr[i] and arr[j] are considered to be "out of order". To correct an inversion, we can swap adjacent elements.

    vector<int> arr {8,4,2,1};

    // ~ Method 1
    // int count=0;
    // for(int i=0;i<arr.size();i++){
    //     for(int j=0;j<arr.size();j++){
    //         count = arr[i] > arr[j] ? count+1 : count;
    //     }
    // }
    // cout<<count<<endl;

    // ~ Method 2 : Merge Sort
    
    return 0;
}