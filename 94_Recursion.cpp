#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &v, int target)
{
    if (target == 0)
    {
        return 0;
    }
    if (target < 0)
    {
        return INT_MAX;  // Updated this line
    }
    int mini = INT_MAX;
    for (int i = 0; i < v.size(); i++)
    {
        int ans = solve(v, target - v[i]);
        if (ans != INT_MAX)
            mini = min(mini, ans + 1);
    }

    return mini;
}

int main()
{
    // * Recursion-4

    // ~ 1.You have to find minimum no. of elements required to reach target sum when input is arr of n distinct element and target is given

    vector<int> v{1, 2};
    int target = 5;
 
    int ans = solve(v, target);
    if (ans == INT_MAX)
    {
        cout << "Target sum not possible with the given elements." << endl;
    }
    else
    {
        cout << "Answer is: " << ans << endl;
    }

    return 0;
}
