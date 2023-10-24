#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    // * Integer to Roman

    int num = 27;

    string romanSymbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    // map iterate (larger to smaller value)
    string ans = "";

    for (int i = 0; i < 13; i++)
    {
        while (num >= values[i])
        {
            ans += romanSymbols[i];
            num -= values[i];
        }
    }
    cout<<ans;
    
    return 0;
}