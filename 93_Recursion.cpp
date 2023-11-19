#include <bits/stdc++.h>
using namespace std;

// ~ Array is sorted or not

// bool checkSorted(vector<int> &v, int &n, int i)
// {
//     if (i == n - 1)
//     {
//         return true;
//     }

//     if (v[i + 1] <= v[i])
//     {
//         return false;
//     }

//     return checkSorted(v, n, i + 1);
// }

// ~ Binary Search

// int binarySearch(vector<int> v, int s, int e, int key)
// {
//     if (s > e)
//     {
//         return -1;
//     }
//     int mid = (s + e) / 2;
//     if (v[mid] == key)
//     {
//         return mid;
//     }
//     if(v[mid]<key){
//         return binarySearch(v,mid+1,e,key);
//     }
//     else{
//         return binarySearch(v,mid,e+1,key);
//     }
// }

// ~ Subsequence of String

void printSubsequence(string str,string output,int i){
    if(i>=str.length()){
        cout<<output<<endl;
        return;
    }
    printSubsequence(str,output,i+1);

    output.push_back(str[i]);
    printSubsequence(str,output,i+1);
}

int main()
{
    // * Recursion - 3

    // ~ Array is sorted or not

    // vector<int> v{2, 3, 7, 10, 14};
    // int n = v.size();
    // int i = 0;

    // bool isSorted = checkSorted(v, n, i);

    // if (isSorted)
    // {
    //     cout << "Array is sorted" << endl;
    // }
    // else
    // {
    //     cout << "Array is not sorted" << endl;
    // }

    // ~ Binary Search

    // vector<int> v{2, 3, 7, 10, 14, 1, 12};
    // int n = v.size();
    // int s = 0;
    // int e = n - 1;
    // int target = 1;

    // int ans = binarySearch(v, s, e, target);

    // cout << "Answer is: " << ans << endl;

    // ~ Subsequence of String

    string str = "abc";
    string output = "";

    int i=0;
    printSubsequence(str,output,i);

    return 0;
}