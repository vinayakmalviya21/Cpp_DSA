#include<iostream>
#include<bits/stdc++.h>
using namespace std; 

int main(){

    // * Valid Anagram

    // ! Approach 1 (Sort and compare)

    // string s="rat";
    // string t="car";

    // if(s.length()!= t.length()){
    //     cout<<"False"<<endl;
    //     return 0;
    // }
    // else{
    //     sort(s.begin(),s.end());
    //     sort(t.begin(),t.end());
    //     for(int i=0;i<s.length();i++){
    //         if(s[i]!=t[i]){
    //             cout<<"False"<<endl;
    //             return 0;
    //         }
    //     }
    //     cout<<"True"<<endl;
    // }

    // ! Approach 2 (Counting and compare)

    string s="anagram";
    string t="margana";

    int freqTable[256]={0};
    for(int i=0;i<s.size();i++){
        freqTable[s[i]]++;
    }

    for(int i=0;i<t.size();i++){
        freqTable[t[i]]--;
    }

    for(int i=0;i<256;i++){
        if(freqTable[i] != 0){
            cout<<"False"<<endl;
            return 0;
        }
    }

    cout<<"True"<<endl;


    return 0;
}