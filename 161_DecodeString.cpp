#include <iostream>
#include <stack>
#include <string>
#include <cctype>    // for isdigit
#include <algorithm> // for reverse
using namespace std;

string decodeString(string s)
{
    stack<string> st;
    for (auto ch : s)
    {
        if (ch == ']')
        {
            string stringToRepeat = "";
            while (!st.empty() && st.top() != "[")
            {
                string top = st.top();
                stringToRepeat += top;
                st.pop();
            }
            st.pop(); // pop '['

            string numericTimes = "";
            while (!st.empty() && isdigit(st.top()[0]))
            {
                numericTimes += st.top();
                st.pop();
            }
            reverse(numericTimes.begin(), numericTimes.end());
            int n = stoi(numericTimes);

            string currentDecode = "";
            while (n--)
            {
                currentDecode += stringToRepeat;
            }
            st.push(currentDecode);
        }
        else if (ch != '[')
        {
            string temp(1, ch);
            st.push(temp);
        }
        else
        {
            st.push("[");
        }
    }
    string ans;
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{

    // * Decode String

    string s = "3[a]2[bc]";
    cout << "Decoded string: " << decodeString(s) << endl;
    return 0;
}
