#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    // * Zig-Zag Conversion

    // ! Approach 1

    // string s="PAYPALISHIRING";
    // int numRows=3;

    // if(numRows ==1){
    //     cout<<s<<endl;
    //     return 0;
    // }

    // vector<string> zigzag(numRows);

    // int i=0,row=0;
    // bool direction =1; // 1 -> (T->B)

    // while(true){
    //     if(direction){
    //         while(row<numRows && i<s.size()){
    //             zigzag[row++].push_back(s[i++]);
    //         }
    //         row=numRows-2;
    //     }
    //     else{
    //         while(row>=0 && i<s.size()){
    //             zigzag[row--].push_back(s[i++]);
    //         }
    //         row=1;
    //     }
    //     if(i>=s.size()) break;

    //     direction = !direction;
    // }
    // string ans = "";
    // for(int i=0;i<zigzag.size();i++){
    //     ans += zigzag[i];
    // }
    // cout<<ans<<endl;

    // ! Approach 2

    string s = "PAYPALISHIRING";
    int numRows = 3;

    if (numRows == 1){
        cout<<s<<endl;
        return 0;
    }
    string res = "";
    int increment = 2 * (numRows - 1);
    for (int r = 0; r < numRows; r++)
    {
        for (int i = r; i < s.length(); i = i + increment)
        {
            res += s[i];

            if (r > 0 && r < numRows - 1 && (i + increment - (2 * r) < s.length()))
            {
                res += s[i + increment - (2 * r)];
            }
        }
    }
    cout<<res<<endl;

    return 0;
}