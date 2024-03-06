#include <iostream>
#include <stack>
#include <string>
using namespace std;

string removeDuplicates(string s)
{
    stack<char> st;

    for (int i = 0; i < s.length(); ++i) {
        char c = s[i];
        if (!st.empty() && c == st.top())
        {
            st.pop();
        }
        else
        {
            st.push(c);
        }
    }

    string ans;
    while (!st.empty())
    {
        ans = st.top() + ans;
        st.pop(); 
    }
    return ans;
}

int main()
{
    // * Remove all adjacent duplicates in string

    string s = "abbaca";
    // cout << "Original string: " << s << endl;
    cout << "String after removing duplicates: " << removeDuplicates(s) << endl;
    return 0;
}
