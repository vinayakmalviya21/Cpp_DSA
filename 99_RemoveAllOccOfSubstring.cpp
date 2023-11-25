#include <bits/stdc++.h>
using namespace std;

void removeOcc(string &s, string &part)
{
    int found = s.find(part);

    if (found != string::npos)
    {
        string left_part = s.substr(0, found);
        string right_part = s.substr(found + part.size(), s.size());
        s = left_part + right_part;

        removeOcc(s, part);
    }
    else{
        // base case
        return;
    }
}

int main()
{
    // * Remove All Occurences Of Substring

    string s = "daabcabababcbc";
    string part = "abc";

    removeOcc(s, part);
    cout<<s<<endl;
    
    return 0;
}