#include <bits/stdc++.h>
using namespace std;

string reverseString(string& s,int start,int end){
    if(start>end){
        return s;
    }

    swap(s[start],s[end]);

    return reverseString(s,start+1,end-1);
}

int main()
{
    // * Reverse a string

    string s = "abcde";

    int start = 0;
    int end = s.length()-1;

    cout<<reverseString(s,start,end);

    return 0;
}