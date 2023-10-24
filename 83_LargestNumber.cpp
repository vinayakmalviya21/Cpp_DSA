#include <iostream>
#include <bits/stdc++.h>
using namespace std;

static bool mycomp(string a, string b){
    return (a + b) > (b + a);
}

int main()
{

    // * Largest Number

    vector<int> nums = {10,2};

    vector<string> snums;
    for(auto n:nums){
        snums.push_back(to_string(n));
    }

    sort(snums.begin(),snums.end(),mycomp);

    if(snums[0] == "0"){
        cout<<"0"<<endl;
        return 0;
    }
    
    string ans ="";
    for(auto str:snums){
        ans+= str;
    }
    cout<<ans;

    return 0;
}