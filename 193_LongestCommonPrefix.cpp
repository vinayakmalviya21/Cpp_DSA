#include <iostream>
#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    // If the array is empty, return an empty string
    if (strs.empty())
        return "";

    string ans = "";

    // Loop on characters of the first string
    for (int i = 0; i < strs[0].length(); i++) {
        char ch = strs[0][i];
        bool match = true;

        // Compare this character with all remaining strings at the same index
        for (int j = 1; j < strs.size(); j++) {
            // If the string is shorter than index i or characters don't match, break
            if (strs[j].size() <= i || ch != strs[j][i]) {
                match = false;
                break;
            }
        }

        if (!match)
            break;
        else
            ans.push_back(ch);
    }
    return ans;
}

int main()
{
    // * Longest Common Prefix

    vector<string> test = {"flower", "flow", "flight"};

    cout << "Longest common prefix for test: " << longestCommonPrefix(test) << endl;

    return 0;

    return 0;
}