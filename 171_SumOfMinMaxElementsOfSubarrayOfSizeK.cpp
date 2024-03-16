#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> sumofminmaxelements(vector<int> &nums, int k)
{
    deque<int> dq_min, dq_max;
    vector<int> sums;

    // First window of size k
    for (int i = 0; i < k; ++i)
    {
        while (!dq_min.empty() && nums[dq_min.back()] >= nums[i])
            dq_min.pop_back();
        while (!dq_max.empty() && nums[dq_max.back()] <= nums[i])
            dq_max.pop_back();
        dq_min.push_back(i);
        dq_max.push_back(i);
    }

    sums.push_back(nums[dq_min.front()] + nums[dq_max.front()]);

    // Remaining windows
    for (int i = k; i < nums.size(); i++)
    {
        if (!dq_min.empty() && i - dq_min.front() >= k)
            dq_min.pop_front();
        if (!dq_max.empty() && i - dq_max.front() >= k)
            dq_max.pop_front();
        while (!dq_min.empty() && nums[dq_min.back()] >= nums[i])
            dq_min.pop_back();
        while (!dq_max.empty() && nums[i] >= nums[dq_max.back()])
            dq_max.pop_back();
        dq_min.push_back(i);
        dq_max.push_back(i);
        sums.push_back(nums[dq_min.front()] + nums[dq_max.front()]);
    }
    return sums;
}

int main()
{
    vector<int> nums = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    int finalSum = 0;

    vector<int> ans = sumofminmaxelements(nums, k);
    cout << "Sums of min max elements in subarrays of size " << k << " are: ";
    for (int sum : ans)
    {
        cout << sum << " ";
        finalSum = finalSum+sum;
    }
    cout <<endl<<"Final sum is: "<< finalSum << endl;

    return 0;
}
