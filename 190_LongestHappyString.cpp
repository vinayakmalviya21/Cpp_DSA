#include <iostream>
#include <string>
#include <queue>
using namespace std;

string longestDiverseString(int a, int b, int c)
{
    priority_queue<pair<int, char>> pq;
    if (a > 0)
        pq.push({a, 'a'});
    if (b > 0)
        pq.push({b, 'b'});
    if (c > 0)
        pq.push({c, 'c'});

    string result = "";
    while (!pq.empty())
    {
        pair<int, char> first = pq.top();
        pq.pop();
        if (result.length() >= 2 && result[result.length() - 1] == first.second && result[result.length() - 2] == first.second)
        {
            if (pq.empty())
                break;
            pair<int, char> second = pq.top();
            pq.pop();
            result += second.second;
            second.first--;
            if (second.first > 0)
                pq.push(second);
            pq.push(first);
        }
        else
        {
            result += first.second;
            first.first--;
            if (first.first > 0)
                pq.push(first);
        }
    }
    return result;
}

int main()
{
    // * Longest Happy String

    // ! A string s is called happy if it satisfies the following conditions:
    // ! s only contains the letters 'a', 'b', and 'c'.
    // ! s does not contain any of "aaa", "bbb", or "ccc" as a substring.
    // ! s contains at most a occurrences of the letter 'a'.
    // ! s contains at most b occurrences of the letter 'b'.
    // ! s contains at most c occurrences of the letter 'c'.
    // ! Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".
    // ! A substring is a contiguous sequence of characters within a string.

    int a = 1, b = 1, c = 7;
    string result = longestDiverseString(a, b, c);
    cout << "Longest happy string: " << result << endl;

    return 0;
}