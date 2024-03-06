#include <iostream>
#include <stack>
#include <string>
using namespace std;

int countRev(string s) {
    if (s.size() & 1)  
        return -1;

    int ans = 0;
    stack<char> st;

    for (char ch : s) {
        if (ch == '(') {
            st.push(ch);
        } else {
            if (!st.empty() && st.top() == '(') {
                st.pop();
            } else {
                st.push(ch);
            }
        }
    }

    // After the first loop, we count unbalanced brackets in the stack
    while (!st.empty()) {
        char a = st.top();
        st.pop();
        char b = st.top();
        st.pop();
        // Count each pair of unbalanced brackets as a single reversal
        if (a == b) 
            ans += 1;
        else
            ans += 2;
    }
    return ans;
}

int main() {

    // * Minimum Bracket Reversal
    // ! Kitne brackets ko reverse krna pdega for correct string sequence

    string s = ")(())(((";
    cout << countRev(s);
    return 0;
}
