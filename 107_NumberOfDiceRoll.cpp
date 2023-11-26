#include <iostream>
using namespace std;

int numRollsToTarget(int n, int k, int target) {
    
    if(target<0){
        return 0;
    }    
    if(target==0 && n==0){
        return 1;
    }    
    if(target!=0 && n==0){
        return 0;
    }    
    if(target==0 && n!=0){
        return 0;
    }    

    int ans=0;
    for(int i=1;i<=k;i++){
        ans = ans + numRollsToTarget(n-1,k,target-i);
    }
    return ans;
}

int main()
{

    // * Number Of Dice Roll with Target Sum

    // ! You have n dice, and each die has k faces numbered from 1 to k.
    // ! Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the dice, so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 10^9 + 7.

    int n = 1, k = 6, target = 3;

    cout<<"Answer: "<<numRollsToTarget(n,k,target);

    return 0;
}