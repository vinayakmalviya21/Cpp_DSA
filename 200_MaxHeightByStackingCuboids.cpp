#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(vector<int> &base, vector<int> &newBox)
{
    return newBox[0] <= base[0] && newBox[1] <= base[1] && newBox[2] <= base[2];
}

int solve(vector<vector<int>> &cuboids, int i, int prev, vector<vector<int>> &dp)
{
    if (i < 0)
        return 0;
    if (dp[i][prev] != -1)
        return dp[i][prev];

    int take = 0;
    if (prev == cuboids.size() || check(cuboids[prev], cuboids[i]))
    {
        take = cuboids[i][2] + solve(cuboids, i - 1, i, dp);
    }

    int notTake = solve(cuboids, i - 1, prev, dp);
    return dp[i][prev] = max(take, notTake);
}

int maxHeight(vector<vector<int>> &cuboids)
{
    int n = cuboids.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    // Sorting each cuboid and all cuboids based on their dimensions
    for (auto &a : cuboids)
    {
        sort(a.begin(), a.end());
    }
    sort(cuboids.begin(), cuboids.end());

    return solve(cuboids, n - 1, n, dp);
}

int main()
{
    // * Maximum Height By Stacking Cuboids
    // ! Given n cuboids where the dimensions of the ith cuboid is cuboids[i] = [widthi, lengthi, heighti] (0-indexed). Choose a subset of cuboids and place them on each other.
    // ! You can place cuboid i on cuboid j if widthi <= widthj and lengthi <= lengthj and heighti <= heightj. You can rearrange any cuboid's dimensions by rotating it to put it on another cuboid.
    // ! Return the maximum height of the stacked cuboids.

    vector<vector<int>> cuboids = {
        {1, 1, 1},
        {2, 2, 2},
        {3, 3, 3}};

    cout << "Maximum height of stacked cuboids: " << maxHeight(cuboids) << endl;

    return 0;
}