#include <iostream>
#include <vector>
using namespace std;

void generateParenthesisHelper(vector<string> &ans, int n, int open, int close, string &output) {
    if (open == 0 && close == 0) {
        ans.push_back(output);
        return;
    }

    if (open > 0) {
        output.push_back('(');
        generateParenthesisHelper(ans, n, open - 1, close, output);
        output.pop_back();
    }

    if (close > open) {
        output.push_back(')');
        generateParenthesisHelper(ans, n, open, close - 1, output);
        output.pop_back();
    }
}

int main() {
    // * 22. Generate Parentheses (Leetcode)
    // ! Input: n = 3
    // ! Output: 
    // ! ["((()))","(()())","(())()","()(())","()()()"]

    vector<string> ans;
    int n = 3;
    int open = n;
    int close = n;
    string output;
    generateParenthesisHelper(ans, n, open, close, output);

    // Print the generated parentheses
    cout << "[";
    for (int i = 0; i < ans.size(); ++i) {
        cout << "\"" << ans[i] << "\"";
        if (i < ans.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;

    return 0;
}
