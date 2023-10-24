#include <iostream>
#include <bits/stdc++.h>
using namespace std;

std::array<int, 256> calculateHash(string s)
{
    std::array<int, 256> hash;
    fill(hash.begin(), hash.end(), 0);
    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i]]++;
    }
    return hash;
}

int main()
{
    // * Group Anagrams

    // ! Approach 1 Hash without sorting

    // vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    // map<std::array<int, 256>, vector<string>> mp;

    // for (auto str : strs)
    // {
    //     mp[calculateHash(str)].push_back(str);
    // }

    // vector<vector<string>> ans;
    // for (auto it = mp.begin(); it != mp.end(); it++)
    // {
    //     ans.push_back(it->second);
    // }

    // for (int i = 0; i < ans.size(); i++)
    // {
    //     for (int j = 0; j < ans[i].size(); j++)
    //     {
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // ! Approach 2 Sorting with map

    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

    map<string,vector<string>> mp;

    for(auto str:strs){
        string s = str;
        sort(s.begin(),s.end());
        mp[s].push_back(str);
    }

    vector<vector<string>>ans;
    for(auto it=mp.begin(); it!=mp.end();it++){
        ans.push_back(it->second);
    }

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}