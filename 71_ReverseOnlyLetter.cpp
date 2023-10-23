#include<iostream>
#include<bits/stdc++.h>
using namespace std; 

int main(){

    // * Reverse Only Letter

    // ! Approach 1

    // string s = "a-bC-dEf-ghIj";

    // int i=0;
    // int n = s.length();
    // int j= n-1;

    // while(i<j){
    //     if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
    //         if((s[j]>='a' && s[j]<='z') || (s[j]>='A' && s[j]<='Z')){
    //             swap(s[i],s[j]);
    //             i++;
    //             j--;
    //         }
    //         else{
    //             j--;
    //         }
    //     }
    //     else{
    //         i++;
    //     }
    // }
    // cout<<s<<endl;

    // ! Approach 2

    string s = "a-bC-dEf-ghIj";

    int i=0;
    int n = s.length();
    int j= n-1;

    while(i<j){
        if(isalpha(s[i]) && isalpha(s[j])){
            swap(s[i],s[j]);
                i++;
                j--;
        }
        else if(!isalpha(s[i])){
            i++;
        }
        else{
            j--;
        }
    }
    cout<<s<<endl;

    return 0;
}