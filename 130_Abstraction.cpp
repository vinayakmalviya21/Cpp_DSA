#include <bits/stdc++.h>
using namespace std;

int main()
{
    // * Abstraction i.e. delivering only essential information to outer world while masking background details.

    vector<int> v={3,4,1,2};
    sort(v.begin(),v.end());
    for(auto i:v){
        cout<<i<<endl;
    }

    return 0;
}