#include <bits/stdc++.h>
using namespace std;

int lastOccurence(string& str,char& x,int n,int i){
    
    if(i<0){
        return -1;
    }

    if(str[i] == x){
        return i;
    }

    return lastOccurence(str,x,n,i-1);
}

int main()
{
    // * Last Occurence of char by recursion

    string str = "abcddefg";
    char x ='d';
    int n = str.length()-1;
    int i=n;

    int ans = lastOccurence(str,x,n,i);
    cout<<"Answer is: "<<ans;

    return 0;
}