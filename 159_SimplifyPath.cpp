#include <iostream>
#include <stack>
#include <string>
using namespace std;

void buildAns(stack<string>& s, string& ans) {
    if (s.empty()) {
        return;
    }
    string minPath = s.top();
    s.pop();
    buildAns(s, ans);
    ans += minPath;
}

string simplifyPath(string path) {
    stack<string> s;
    int i = 0;
    while (i < path.size()) {
        int start = i;
        int end = i + 1;
        while (end < path.size() && path[end] != '/') {
            ++end;
        }
        string minPath = path.substr(start, end - start);
        i = end;
        if (minPath == "/" || minPath == "/.") {
            continue;
        }
        if (minPath != "/..") {
            s.push(minPath);
        } else if (!s.empty()) {
            s.pop();
        }
    }
    string ans = s.empty() ? "/" : "";
    buildAns(s, ans);
    return ans;
}

int main() {
    
    // * Simplify path
    // ! In a Unix-style file system, a period '.' refers to the current directory, a double period '..' refers to the directory up a level, and any multiple consecutive slashes (i.e. '//') are treated as a single slash '/'. For this problem, any other format of periods such as '...' are treated as file/directory names.

    string path = "/a/./b/../../c/";
    cout << "Original path: " << path << endl;
    cout << "Simplified path: " << simplifyPath(path) << endl;
    return 0;
}
