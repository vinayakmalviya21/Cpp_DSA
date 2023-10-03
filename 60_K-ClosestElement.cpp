#include <iostream>
#include<vector>
using namespace std;

// * 2. Binary Search Approach + 2 pointer approach

int lowerBound(vector<int>a,int x){
    int s=0;
    int e=a.size()-1;
    int ans=e;
    
    while (s<=e)
    {
        int mid=(s+e)/2;
        if (a[mid] >=x)
        {
            ans=mid;
            e=mid-1;
        }
        else if(x>a[mid])
        {
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return ans;
}

int main()
{

    // ~ Find k-closest element


    vector<int> a{1,2,3,4,5};
    int k =4,x=3;
    vector<int> ans;

    // * 1. Two pointer approach

    // int l=0;
    // int h=a.size()-1;
    
    // while (h - l >= k)
    // {
    //     if (x - a[l] > a[h] - x)
    //     {
    //         l++;
    //     }
    //     else
    //     {
    //         h--;
    //     }
    // }
    // for(int i=l;i<=h;i++){
    //     ans.push_back(a[i]);
    // }
    
    // for(int i=0;i<ans.size();i++){
    //     cout<<ans[i]<<" ";
    // }
    
    // * 2. Binary Search Approach + 2 pointer approach

    int h = lowerBound(a,x);
    int l=h-1;
    while(k--){
        if(l<0){
            h++;
        }
        else if(h>=a.size()){
            l--;
        }
        else if(x-a[l] > a[h]-x){
            h++;
        }
        else{
            l--;
        }
    }
    for(int i=l+1;i<h;i++){
        ans.push_back(a[i]);
    }
    
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    

    return 0;
}