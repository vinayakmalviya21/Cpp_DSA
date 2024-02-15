#include<bits/stdc++.h>
using namespace std; 

void countArrangementHelper(vector<int>&v,int&n,int&ans,int currNum){

        if(currNum == n+1){
            for(int i=1;i<=n;i++){
                cout<<v[i]<<" ";
            }
            cout<<endl;
            ++ans;
            return;
        }

        for(int i=1;i<=n;i++){
            if(v[i] == 0 && (currNum%i == 0 || i%currNum == 0)){
                v[i] = currNum;
                countArrangementHelper(v,n,ans,currNum+1);
                v[i] = 0;
            }
        }
    }

    int countArrangement(int n) {
        vector<int>v(n+1);
        int ans=0;
        countArrangementHelper(v,n,ans,1);
        return ans;
    }

int main(){

// * Beautiful Arrangement

// Suppose you have n integers labeled 1 through n. A permutation of those n integers perm (1-indexed) is considered a beautiful arrangement if for every i (1 <= i <= n), either of the following is true:
// perm[i] is divisible by i.
// i is divisible by perm[i].
// Given an integer n, return the number of the beautiful arrangements that you can construct.

int n = 2;
cout<< countArrangement(n);

return 0;

}