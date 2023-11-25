#include <bits/stdc++.h>
using namespace std;

void printSubarray(vector<int> &nums, int start, int end)
{

    if (end == nums.size())
    {
        return;
    }

    for (int i = start; i <= end; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    printSubarray(nums, start, end + 1);
}

int main()
{
    // * Print all subarrays using Recursion

    vector<int> nums{1, 2, 3, 4, 5};

    printSubarray(nums, 0,0);

    return 0;
}