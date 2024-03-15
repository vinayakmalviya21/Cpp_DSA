#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> ans;

    // first window of k size
    for (int i = 0; i < k; ++i) {
        // chote element remove krdo
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }
        // inserting index, so that we can checkout of window element
        dq.push_back(i);
    }

    // store answer for first window
    ans.push_back(nums[dq.front()]);

    // remaining windows ko process
    for (int i = k; i < nums.size(); i++) {
        // out of window element ko remove krdia
        if (!dq.empty() && i - dq.front() >= k) {
            dq.pop_front();
        }

        // ab fir se current element k liye chote element ko remove krna h
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }
        // inserting index, so that we can checkout of window element
        dq.push_back(i);

        // current window ka answer store krna h
        ans.push_back(nums[dq.front()]);
    }
    return ans;
}

int main() {
    // * SlidingWindowMaximum
    // ! You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right.
    // You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.

    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> result = maxSlidingWindow(nums, k);
    
    cout << "Max sliding window: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
