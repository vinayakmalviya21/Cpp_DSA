#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int>& counts, vector<int>& quantity, int ithCustomer){
        if(ithCustomer == quantity.size()) return true;

        for(int i = 0; i < counts.size(); i++){
            if(counts[i] >= quantity[ithCustomer]){
                counts[i] -= quantity[ithCustomer];
                if(solve(counts, quantity, ithCustomer + 1)) return true;
                counts[i] += quantity[ithCustomer];
            }
        }
        return false;
    }

    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int,int> countMap;
        for(auto num:nums)
            countMap[num]++;
        vector<int> counts;
        for(auto it: countMap)
            counts.push_back(it.second);
        sort(quantity.rbegin(), quantity.rend());
        return solve(counts, quantity, 0);
    }

int main()
{
    // * Distributing Repeating INTs
    // You are given an array of n integers, nums, where there are at most 50 unique values in the array.
    // You are also given an array of m customer order quantities, quantity, where quantity[i] is the amount
    // of integers the ith customer ordered. Determine if it is possible to distribute nums such that:
    // The ith customer gets exactly quantity[i] integers,
    // The integers the ith customer gets are all equal, and
    // Every customer is satisfied.
    // Return true if it is possible to distribute nums according to the above conditions.

    vector<int> nums{1, 2, 3, 4};
    vector<int> quantity{2}; // Note: You need to initialize vector<int> with curly braces {}

    bool result = canDistribute(nums, quantity);

    cout << "Result: " << (result ? "true" : "false") << endl;

    return 0;
}