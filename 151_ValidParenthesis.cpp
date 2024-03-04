#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else
        {
            if (!st.empty())
            {
                char topCh = st.top();
                if (ch == ')' && topCh == '(')
                {
                    st.pop();
                }
                else if (ch == '}' && topCh == '{')
                {
                    st.pop();
                }
                else if (ch == ']' && topCh == '[')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
    if (st.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    // * Valid Parenthesis

    string s = "()[]{}";

    if (isValid(s))
    {
        cout << "Valid Parenthesis" << endl;
    }
    else
    {
        cout << "Invalid Parenthesis" << endl;
    }

    return 0;
}
