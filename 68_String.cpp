#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// * 3. Valid Palindrome

// bool checkpalindrome(string s, int i, int j)
//     {
//         while(i<=j)
//         {
//             if(s[i]!=s[j])
//             {
//                 return false;
//             }
//             else
//             {
//                 i++;
//                 j--;
//             }
//         }
//         return true;
//     }

// bool validPalindrome(string s)
// {
//     int i=0;
//     int j=s.length()-1;

//     while(i<=j)
//     {
//         if(s[i]!=s[j])
// {
// ek barr i ko remove, ek baar j ko remove
//     return checkpalindrome(s, i+1, j) || checkpalindrome(s, i, j-1);
// }
// else{
// s[i] == s[j]
//         i++;
//         j--;
//     }
// }
//     return true;
// }

// * 4. Palindromic Substrings

int expandAroundIndex(string s, int i, int j)
{
    int count = 0;
    while (i >= 0 && j < s.length() && s[i] == s[j])
    {
        count++;
        i--;
        j++;
    }
    return count;
}

int main()
{

    // * 1. Remove Adjacent Character in String

    // string s = "azxxzy";
    // string ans;
    // ans.push_back(s[0]);

    // for (int i = 1; i < s.length(); i++)
    // {

    //     if (s[i] == ans.back())
    //     {
    //         ans.pop_back();
    //     }
    //     else
    //     {
    //         ans.push_back(s[i]);
    //     }
    // }
    // cout<<ans;

    // * 2. Remove All Occurrences of a Substring

    // string s = "daabcbaabcbc", part = "abc";

    //  while(s.length()!=0 && s.find(part) < s.length()){
    //     s.erase(s.find(part) , part.length());
    //  }
    // cout<<s;

    // * 3. Valid Palindrome
    // ! We can delete atmost one character to make it palindrome

    // string s = "abach";
    // bool result = validPalindrome(s);
    // cout << (result ? "true" : "false") <<endl;

    // * 4. Minimum Time Difference
    // ! Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.

    // vector <string> timePoints ={"23:59","00:00"};
    // vector<int> minutes;

    // for(int i=0;i<timePoints.size();i++){
    //     string curr = timePoints[i];

    // ~ stoi convert string to integer

    //     int hours = stoi(curr.substr(0,2));
    //     int mins = stoi(curr.substr(3,2));
    //     int totalMins = hours*60 + mins;
    //     minutes.push_back(totalMins);
    // }

    // sort(minutes.begin(),minutes.end());

    // int mini = INT_MAX;
    // int n = minutes.size();

    // for(int i=0;i<n;i++){
    //     int diff = minutes[i+1] - minutes[i];
    // }

    // int lastDiff = (minutes[0]+ 1440) - minutes[n-1];
    // mini = min(mini,lastDiff);

    // cout<<mini;

    // * 4. Palindromic Substrings
    // ! return the number of palindromic substrings in it.

    string s = "noon";
    int count = 0;
    int n = s.length();
    for (int center = 0; center < n; center++)
    {
        // odd
        int oddKaAns = expandAroundIndex(s, center, center);
        count = count + oddKaAns;
        // odd
        int evenKaAns = expandAroundIndex(s, center, center + 1);
        count = count + evenKaAns;
    }
    cout<<count<<endl;

    return 0;
}