#include<iostream>
#include<bits/stdc++.h>
using namespace std; 

int main(){

    // * Find Index of First Occurence

    string haystack={"sadbutsad"};
    string needle={"sad"};

    int n = haystack.size();
    int m = needle.size();

    for(int i=0;i<=n-m;i++){
        for(int j=0;j<m;j++){
            if(needle[j] != haystack[i+j]){
                break;
            }
            
            if(j == m-1){
                cout<<i<<endl;
                return 0;
            }
        }
    }
    cout<<"-1"<<endl;
    
    return 0;
}