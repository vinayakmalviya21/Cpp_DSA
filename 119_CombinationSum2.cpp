#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

void combinationSum_helper(vector<int> &candidates, int target, vector<int> &v, vector<vector<int>> &ans, int index) {
    if (target == 0) {
        ans.push_back(v);
        return;
    }
    if (target < 0 || index >= candidates.size()) {
        return;
    }

    for (int i = index; i < candidates.size(); i++) {
        v.push_back(candidates[i]);
        combinationSum_helper(candidates, target - candidates[i], v, ans, i + 1);
        v.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> v;
    combinationSum_helper(candidates, target, v, ans, 0);
    set<vector<int>> st;
    for (auto e : ans) {
        st.insert(e);
    }
    ans.clear();
    for (auto e : st) {
        ans.push_back(e);
    }
    return ans;
}

int main() {
    // * Combination Sum - 2
    // Given a collection of candidate numbers (candidates) and a target number (target),
    // find all unique combinations in candidates where the candidate numbers sum to target.
    // Each number in candidates may only be used once in the combination.

    vector<int> candidates{2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result = combinationSum2(candidates, target);

    // Print the result
    for (const auto &combination : result) {
        cout << "[ ";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
