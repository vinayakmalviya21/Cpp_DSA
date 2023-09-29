#include<bits/stdc++.h>
using namespace std; 

int main(){

    vector<vector<int> > v{
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };

    int m = v.size();
    int n = v[0].size();

    for(int startCol = 0;startCol<n;startCol++){

        // Even no. of col => Top to Bottom
        if((startCol & 1) == 0){
            for(int i=0;i<m;i++){
                cout<<v[i][startCol]<<" ";
            }
            cout<<endl;
        }

        else{

        // Odd no. of col => Bottom to Top
        for(int i=m-1;i>=0;i--){
                cout<<v[i][startCol]<<" ";
            }
            cout<<endl;
        }

    }


    return 0;
}