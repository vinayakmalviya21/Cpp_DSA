#include<bits/stdc++.h>
#include<vector>
using namespace std; 

bool isPossibleSolution(vector<long long int> trees, long long int m, long long int mid)
{
    long long int woodCollected = 0;
    for(long long int i=0;i<trees.size();i++){
        if(trees[i]>mid){
            woodCollected+= trees[i]-mid;
        }
    }
    return woodCollected >= m; 
}

int main(){
    
    // * EKO SPOJ Problem

    long long int n = 4; // No. of trees
    long long int m = 7; // Wood amount required

    vector<long long int> trees{20,15,10,17};

    long long int ans=-1; // to find sawblade's height

    long long int start = 0 , end;

    end = *max_element(trees.begin(),trees.end());

    while(start <= end){
        long long int mid = start + (end-start)/2;
        if(isPossibleSolution(trees,m,mid)){
            ans = mid;
            start = mid+1;
        }
        else{
            end=mid-1;
        }
    }
    cout<<ans<<endl;

    return 0;
}