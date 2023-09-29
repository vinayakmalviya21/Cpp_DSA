#include<bits/stdc++.h>
using namespace std; 

int main(){

    // ! First Repeating Element of array

    vector<int> v = {1,5,3,4,3,5,6};

    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            if(v[i] == v[j]){
                cout<<i<<endl;
                return 0;
            }
        }
    }


    return 0;
}