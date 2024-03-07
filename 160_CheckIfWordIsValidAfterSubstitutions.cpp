#include <bits/stdc++.h>
using namespace std;

// ~ Approach 1
// bool isValid(string s) {
//         if(s.size() == 0){
//             return true;
//         }
//         int found = s.find("abc");
//         if(found != string::npos){
            // found
//             string tleft = s.substr(0,found);
//             string tright = s.substr(found+3,s.size());
//             return isValid(tleft+tright);
//         }
//         return false;
// }

// ~ Approach 2
bool isValid(string s) {
        if(s[0] != 'a') return false;

        stack<char> st;
        for(char ch: s){
            if(ch == 'a'){
                st.push(ch);
            }
            else if(ch == 'b'){
                if(!st.empty() && st.top() == 'a'){
                    st.push('b');
                }
                else{
                    return false;
                }
            }
            else{
                // ch == 'c'
                if(!st.empty() && st.top() == 'b'){
                    st.pop();
                    if(!st.empty() && st.top() == 'a'){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        return st.empty();
}

int main()
{
    // * Check If Word Is Valid After Substitutions
    // ! Given a string s, determine if it is valid.A string s is valid if, starting with an empty string t = "", you can transform t into s after performing the following operation any number of times:
    // ! Insert string "abc" into any position in t. More formally, t becomes tleft + "abc" + tright, where t == tleft + tright. Note that tleft and tright may be empty. Return true if s is a valid string, otherwise, return false.

    string s = "aabcbc";

    if(isValid){
        cout<<"Answer is: True"<<endl;
    }
    else{
        cout<<"Answer is: False"<<endl;
    }

    return 0;
}