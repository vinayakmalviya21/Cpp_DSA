#include <bits/stdc++.h>
using namespace std;

int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int maxLen =0;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(ch == '('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    int len = i - st.top();
                    maxLen = max(len,maxLen);
                }
            }
        }
        return maxLen;
}

int main()
{
    // * LongestValidParentheses

    string s = "(()";

    cout<<longestValidParentheses(s);

    return 0;
}