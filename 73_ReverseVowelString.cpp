#include<iostream>
#include<bits/stdc++.h>
using namespace std; 

int main(){

    // * Reverse vowels of string

    string s = "aA";

    int i=0;
    int n = s.length();
    int j= n-1;

    while(i<=j){
        if((s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U') &&
           (s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u' || s[j]=='A' || s[j]=='E' || s[j]=='I' || s[j]=='O' || s[j]=='U')){
            swap(s[i],s[j]);
            i++;
            j--;
        }
        else if (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
            j--;
        }
        else{
            i++;
        }
    }
    cout<<s<<endl;


    return 0;
}
