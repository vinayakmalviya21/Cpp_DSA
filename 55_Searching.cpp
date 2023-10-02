#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// int binarySearch(int arr[], int size, int target)
// {
//     int start = 0;
//     int end = size - 1;

//     while (start <= end)
//     {
//         int mid = start + (end - start) / 2;
//         int element = arr[mid];

//         if (element == target)
//         {
//             return mid;
//         }
//         else if (element < target)
//         {
//             start = mid + 1;
//         }
//         else
//         {
//             end = mid - 1;
//         }
//     }
//     return -1;
// }

int main()
{

    // ! Binary Search

    // int arr[] = {2, 4, 6, 8, 10, 12, 14};
    // int size = 7;
    // int target = 2;

    // int indexOftarget = binarySearch(arr, size, target);

    // if (indexOftarget == -1)
    // {
    //     cout << "Target not found" << endl;
    // }
    // else
    // {
    //     cout << "Target found at " << indexOftarget << endl;
    // }

    // ! Binary Search Using STL

    // vector<int> v{1,2,3,4,5,6};
    // if(binary_search(v.begin(),v.end(),2)){
    //     cout<< "Found"<<endl;
    // }
    // else{
    //     cout<<"Not found"<<endl;
    // }

    // int arr[] = {1,2,3,4,5,6};
    // int size = 6;
    // if(binary_search(arr,arr + size,3)){
    //     cout<< "Found"<<endl;
    // }
    // else{
    //     cout<<"Not found"<<endl;
    // }

    // ~ 1. Find first occurence of an element

    // vector<int> v{1,3,4,4,4,4,6,7};
    // int target = 4;
    // int start = 0;
    // int end = v.size()-1;
    // int ans = -1;

    //  while (start <= end)
    // {
    //     int mid = start + (end - start) / 2;
    //     int element = v[mid];

    //     if (element == target)
    //     {
    //         ans = mid;
    //         end = mid-1;
    //     }
    //     else if (element < target)
    //     {
    //         start = mid + 1;
    //     }
    //     else
    //     {
    //         end = mid - 1;
    //     }
    // }

    // cout<<ans<<endl;

    // ~ 2. Find last occurence of an element

    // vector<int> v{2,5,7,7,7,7,7,9,9,10};
    // int target = 7;
    // int start = 0;
    // int end = v.size()-1;
    // int ans = -1;

    //  while (start <= end)
    // {
    //     int mid = start + (end - start) / 2;
    //     int element = v[mid];

    //     if (element == target)
    //     {
    //         ans = mid;
    //         start = mid+1;
    //     }
    //     else if (target > element)
    //     {
    //         start = mid + 1;
    //     }
    //     else
    //     {
    //         end = mid - 1;
    //     }
    // }

    // cout<<ans<<endl;

    // ~ 3. Total no. of occurence of an element

    // vector<int> v{2, 4, 4, 4, 4, 4, 4, 6, 8, 10};
    // int target = 4;
    // int start = 0;
    // int end = v.size() - 1;
    // int firstOccurence = -1;
    // int lastOccurence = -1;

    // * First Occurrence Code
    // while (start <= end)
    // {
    //     int mid = start + (end - start) / 2;
    //     int element = v[mid];

    //     if (element == target)
    //     {
    //         firstOccurence = mid;
    //         end = mid - 1;
    //     }
    //     else if (element < target)
    //     {
    //         start = mid + 1;
    //     }
    //     else
    //     {
    //         end = mid - 1;
    //     }
    // }

    // * Reset start and end for the second binary search
    // start = 0;
    // end = v.size() - 1;

    // * Last Occurrence Code
    // while (start <= end)
    // {
    //     int mid = start + (end - start) / 2;
    //     int element = v[mid];

    //     if (element == target)
    //     {
    //         lastOccurence = mid;
    //         start = mid + 1;
    //     }
    //     else if (target > element)
    //     {
    //         start = mid + 1;
    //     }
    //     else
    //     {
    //         end = mid - 1;
    //     }
    // }

    // int totalOccurence = lastOccurence - firstOccurence + 1;
    // cout << totalOccurence << endl;

    // ~ 4. Find missing element when array is from 1 to n using binary search



    // ~ 5. Peak element in Mountain Array

    vector<int> arr{1,2,1,3,5,6,4};
    int start = 0;
    int end = arr.size() - 1;
    int mid;
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        int element = arr[mid];

        if (arr[mid] < arr[mid+1])
        {
            start = mid+1;
        }
        else{
            end = mid;
        }
    }
    cout<<arr[start]<<endl;

    // ~ 6. Find pivot using Binary Search

    // ~ 7. Search in rotated and sorted array

    // ~ 8. Square root using Binary Search

    return 0;
}