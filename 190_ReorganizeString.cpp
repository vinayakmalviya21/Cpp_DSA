#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

string reorganizeString(string S)
{
    vector<int> count(26, 0); // Count of each character
    int n = S.size();

    // Count frequency of each character
    for (char ch : S)
    {
        count[ch - 'a']++;
    }

    // Max heap to store characters based on their frequency
    priority_queue<pair<int, char>> maxHeap;

    // Push characters and their frequencies into maxHeap
    for (int i = 0; i < 26; ++i)
    {
        if (count[i] > 0)
        {
            maxHeap.push({count[i], 'a' + i});
        }
    }

    string result;

    while (!maxHeap.empty())
    {
        // Extract the character with the highest frequency
        auto current = maxHeap.top();
        maxHeap.pop();

        // Append the character to the result
        result += current.second;

        // If there are more instances of the same character, put it back in the heap
        if (!maxHeap.empty())
        {
            auto next = maxHeap.top();
            maxHeap.pop();
            result += next.second;

            // Decrement the frequency and put it back in the heap if it's not zero
            if (--next.first > 0)
            {
                maxHeap.push(next);
            }
        }

        // Decrement the frequency and put it back in the heap if it's not zero
        if (--current.first > 0)
        {
            maxHeap.push(current);
        }
    }

    // If the length of the result string is not equal to the original string, return empty string
    return result.length() == n ? result : "";
}

int main()
{
    // * Reorganize String
    
    string S = "aab";
    cout << "Reorganized String: " << reorganizeString(S) << endl;
    return 0;
}
