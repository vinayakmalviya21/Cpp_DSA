#include<bits/stdc++.h>
using namespace std; 

int main(){

    // ! Find Common Element in 3 sorted array

    int A[] = {1,5,10,20,80,80};
    int n1=6;
    int B[] = {6,7,20,80,80};
    int n2=5;
    int C[] = {3,4,15,20,30,80,80,120};
    int n3=8;

    vector<int> ans;
    set<int> st;

    int i,j,k;
    i=j=k=0;

    while(i<n1 && j<n2 && k<n3){
        if(A[i] == B[j] && B[j] == C[k]){
            // ans.push_back(A[i]);
            st.insert(A[i]);
            i++; j++; k++;
        }
        else if(A[i]<B[j]){
            i++;
        }
        else if(B[j]<C[k]){
            j++;
        }
        else{
            k++;
        }
    }

    // For removing duplicate in final answer
    for(auto i : st){
        ans.push_back(i);
    }

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}