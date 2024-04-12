#include <iostream>
#include <vector>
using namespace std;

int solveUsingRecursion(int n,int k){
    if(n==1){
        return k;
    }
    if(n==2){
        return (k + k*(k-1));
    }

    int ans = (solveUsingRecursion(n-2,k)+solveUsingRecursion(n-1,k))*(k-1);
    return ans;
}

int solveUsingMem(int n,int k,vector<int>& dp){
    if(n==1){
        return k;
    }
    if(n==2){
        return (k + k*(k-1));
    }
    if(dp[n] != -1){
        return dp[n];
    }

    dp[n]= (solveUsingMem(n-2,k,dp)+solveUsingMem(n-1,k,dp))*(k-1);
    return dp[n];
}

int solveUsingTab(int n,int k){
    vector<int> dp(n+1,0);
    dp[1]=k;
    dp[2]=(k + k*(k-1));

    for (int i = 3; i <=n; i++)
    {
        dp[i] = (dp[i-2]+dp[i-1])*(k-1);
    }
    return dp[n];
}

int main()
{
    // *  painting a fence with k colors in such a way that no more than two adjacent fences have the same color.
    
    int n=4;
    int k=3;

    // int ans = solveUsingRecursion(n,k);
    vector<int> dp(n+1,-1);
    // int ans = solveUsingMem(n,k,dp);
    int ans = solveUsingTab(n,k);
    cout<<"Ans: "<<ans<<endl;

    return 0;
}