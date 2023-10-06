#include <bits/stdc++.h>
#include <vector>
using namespace std;

bool isPossibleSolution(vector<int> &stalls, int k, int mid)
{
    int c = 1;
    int pos = stalls[0];
    for (int i = 1; i < stalls.size(); i++) // Start from index 1
    {
        if (stalls[i] - pos >= mid)
        {
            c++;
            pos = stalls[i];
        }
        if (c == k)
        {
            return true;
        }
    }
    return false;
}

int main()
{

    // * Aggressive Cow Problem

    int n = 5; // No. of stalls
    vector<int> stalls{10, 1, 2, 7, 5};
    int k = 3; // No. of aggressive cows

    sort(stalls.begin(), stalls.end());

    int start = 0;
    int end = stalls[stalls.size() - 1] - stalls[0];

    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isPossibleSolution(stalls, k, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}
