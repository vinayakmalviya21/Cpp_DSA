#include <iostream>
#include <vector>
#include <set>
using namespace std;

void permuteUniqueHelper(vector<int>& nums, vector<vector<int>>& ans, int start) {
    if (start == nums.size()) {
        ans.push_back(nums);
        return;
    }

    for (int i = start; i < nums.size(); i++) {
        if (i != start && nums[i] == nums[start])
            continue; // Skip duplicate permutations
        swap(nums[i], nums[start]);
        permuteUniqueHelper(nums, ans, start + 1);
        swap(nums[i], nums[start]);
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> ans;
    permuteUniqueHelper(nums, ans, 0);
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
    // Permutation-II: Given a collection of numbers, nums, that might contain duplicates, 
    // return all possible unique permutations in any order.
    vector<int> nums = {1, 1, 2}; // Correct initialization using curly braces

    vector<vector<int>> result = permuteUnique(nums);

    // Print the result
    for (const auto& combination : result) {
        cout << "[ ";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
