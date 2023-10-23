#include<iostream>
#include<bits/stdc++.h>
using namespace std; 

bool cmp(char first, char second){
    return first > second;
}

int main(){

    // * 1. Sort function k andar custom comparator

    string s = "babbar";
    sort(s.begin(),s.end(),cmp);

    cout<<s<<endl;

    return 0;
}