#include <iostream>
using namespace std;

bool isMatchHelper(string& s, int si, string& p, int pi) {
    if (si == s.size() || pi == p.size()) {
        return si == s.size() && pi == p.size();
    }

    if (s[si] == p[pi] || p[pi] == '?') {
        return isMatchHelper(s, si + 1, p, pi + 1);
    }

    if (p[pi] == '*') {
        // treat '*' as empty
        bool caseA = isMatchHelper(s, si, p, pi + 1);

        // let '*' consume one char
        bool caseB = isMatchHelper(s, si + 1, p, pi);
        return caseA || caseB;
    }

    return false;
}

bool isMatch(string s, string p) {
    int si = 0; // pointer index for s string
    int pi = 0; // pointer index for p string

    return isMatchHelper(s, si, p, pi);
}

int main() {
    // Wildcard Matching

    // Given an input string (s) and a pattern (p), implement wildcard pattern matching
    // with support for '?' and '*' where:
    // '?' Matches any single character.
    // '*' Matches any sequence of characters (including the empty sequence).
    // The matching should cover the entire input string (not partial).

    string s = "aa", p = "a";
    cout << "Answer is: " << isMatch(s, p) << endl;

    return 0;
}
