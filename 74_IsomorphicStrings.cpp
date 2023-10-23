#include<iostream>
#include<bits/stdc++.h>
using namespace std; 

int main(){

    // * Isomorphic Strings
    // ! Two strings s and t are isomorphic if the characters in s can be replaced to get t.

    string  s = "foo", t = "bar";

    int hash[256]={0};//mapping char of string 's' to string 't'
        bool isTcharsMapped[256]={0}; //stores if t[i] char already mapped with s[i].

        for(int i=0;i<s.size();i++){
            if(hash[s[i]] ==0 && isTcharsMapped[t[i]]==0){
                hash[s[i]]= t[i];
                isTcharsMapped[t[i]]= true;
            }
        }
        for(int i=0;i<t.size();i++){
            if(char(hash[s[i]]) != t[i]){
                cout<<"False";
                return 0;
            }
        }
        cout<<"True";
        return 0;
}