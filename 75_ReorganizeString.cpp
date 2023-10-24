#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    // * Reorganise string
    // ! rearrange the characters of s so that any two adjacent characters are not the same.

    string s = "aabbcdefgg";

    int n = s.size();

    int hash[26] = {0};

    for (int i = 0; i < n; i++)
    {
        hash[s[i] - 'a']++;
    }

    char max_freq_char;
    int max_freq = INT_MIN;
    for (int i = 0; i < 26; i++)
    {
        if (hash[i] > max_freq)
        {
            max_freq = hash[i];
            max_freq_char = i + 'a';
        }
    }
    int index = 0;
    while (max_freq > 0 && index < n)
    {
        s[index] = max_freq_char;
        max_freq--;
        index += 2;
    }
    if (max_freq != 0)
    {
        cout << "" << endl;
        cout << "Empty" << endl;
        return 0;
    }

    // hash[max_freq - 'a'] = 0;

    for (int i = 0; i < 26; i++)
    {
        while (hash[i] > 0)
        {
            index = index >= n ? 1 : index;
            s[index] = i + 'a';
            hash[i]--;
            index += 2;
        }
    }

    cout << s << endl;

    return 0;
}