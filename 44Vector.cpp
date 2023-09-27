#include <iostream>
#include <vector>
using namespace std;

int main()
{

    // * ----------- Create vector
    // vector<int> arr;

    // ! No. of element present
    // cout<<arr.size()<<endl;

    // ! No. of element it can store
    // cout<<arr.capacity()<<endl;

    // * ----------- 1. Find unique element

    // int n;
    // cout<<"Enter size of array"<<endl;
    // cin>>n;

    // vector<int> arr(n);
    // int ans=0;

    // for(int i=0;i<arr.size();i++){
    //     cin>>arr[i];
    // }

    // for(int i=0;i<arr.size();i++){
    //     ans = ans ^ arr[i];
    // }

    // cout<<"Unique element :"<<ans<<endl;

    // * ----------- 2. Union of array

    // int A[] = {1,2,4,6,8,9};
    // int sizeA = 6;
    // int B[] = {1,3,5,7,9};
    // int sizeB = 4;

    // vector<int> ans;

    // for(int i=0;i<sizeA;i++){
    //     int element = A[i];
    //     for(int j=0;j<sizeB;j++){
    //         if(element == B[j]){
    //             B[j] = -1;
    //         }
    //     }
    // }

    // for(int i=0;i<sizeA;i++){
    //     ans.push_back(A[i]);
    // }

    // for(int i=0;i<sizeB;i++){
    //     ans.push_back(B[i]);
    // }

    // for(int i=0;i<ans.size();i++){
    //     if(ans[i] != -1 )
    //         cout<<ans[i]<<" ";
    // }

    // * ----------- 3. Intersection of array

    // int A[] = {1,2,3,4,4};
    // int sizeA = 4;
    // int B[] = {3,4,4,5,6};
    // int sizeB = 4;

    // vector<int> ans;

    // for(int i=0;i<sizeA;i++){
    //     int element = A[i];
    //     for(int j=0;j<sizeB;j++){
    //         if(element == B[j]){
    //             B[j] = -1;
    //             ans.push_back(A[i]);
    //             }
    //     }
    // }

    // for(int i=0;i<ans.size();i++){
    //     cout<<ans[i]<<" ";
    // }

    // * ----------- 4. Pair Sum

    // vector<int> arr{1,3,5,7,2,4,6};
    // int sum = 9;

    // for(int i=0;i<arr.size();i++){
    //     int element = arr[i];

    //     for(int j=0;j<arr.size();j++){
    //         if(element + arr[j] == sum){
    //             cout<<element<<","<<arr[j]<<endl;
    //         }
    //     }
    // }

    // * ----------- 5. Triplet Sum

    // vector<int> arr{10, 20, 30, 40};
    // int sum = 60;

    // for (int i = 0; i < arr.size(); i++)
    // {
    //     int element1 = arr[i];

    //     for (int j = i+1; j < arr.size(); j++)
    //     {
    //         int element2 = arr[j];

    //         for (int k = j+1; k < arr.size(); k++)
    //         {
    //             int element3 = arr[k];
    //             if (element1 + element2 + element3 == sum)
    //             {
    //                 cout << element1 << "," << element2 << "," << element3 << endl;
    //             }
    //         }
    //     }
    // }

    // * ----------- 6. Four Element Sum

    // vector<int> arr{10, 20, 30, 40, 50, 60, 70};
    // int sum = 160;

    // for (int i = 0; i < arr.size(); i++)
    // {
    //     int a = arr[i];

    //     for (int j = i + 1; j < arr.size(); j++)
    //     {
    //         int b = arr[j];

    //         for (int k = j + 1; k < arr.size(); k++)
    //         {
    //             int c = arr[k];

    //             for (int l = k + 1; l < arr.size(); l++)
    //             {
    //                 int d = arr[l];

    //                 if (a + b + c + d == sum)
    //                 {
    //                     cout << a << "," << b << "," << c << "," << d << endl;
    //                 }
    //             }
    //         }
    //     }
    // }

    // * ----------- 7. Sort 0's and 1's
        


    return 0;
}