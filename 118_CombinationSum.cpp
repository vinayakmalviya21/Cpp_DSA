#include <iostream>
#include <vector>
using namespace std;

void combinationSum_helper(vector<int> &candidates, int target, vector<int> &v, vector<vector<int>> &ans, int index)
{
    if (target == 0)
    {
        ans.push_back(v);
        return;
    }
    if (target < 0 || index >= candidates.size())
    {
        return;
    }

    for (int i = index; i < candidates.size(); i++)
    {
        v.push_back(candidates[i]);
        combinationSum_helper(candidates, target - candidates[i], v, ans, i);
        v.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> v;
    combinationSum_helper(candidates, target, v, ans, 0);
    return ans;
}

int main()
{
    // * Combination Sum
    // Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

    // The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

    vector<int> candidates{2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result = combinationSum(candidates, target);

    // Print the result
    for (const auto &combination : result)
    {
        cout << "[ ";
        for (int num : combination)
        {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
