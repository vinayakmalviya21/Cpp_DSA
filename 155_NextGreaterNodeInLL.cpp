#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

vector<int> nextLargerNodes(ListNode* head) {
    vector<int> ll;
    while (head) {
        ll.push_back(head->val);
        head = head->next;
    }
    stack<int> st;
    vector<int> ans(ll.size());

    for (int i = 0; i < ll.size(); i++) {
        while (!st.empty() && ll[i] > ll[st.top()]) {
            int index = st.top();
            st.pop();
            ans[index] = ll[i];
        }
        st.push(i);
    }
    return ans;
}

int main() {

    ListNode* head = new ListNode(2);
    head->next = new ListNode(1);
    head->next->next = new ListNode(5);

    // * Calling the function to find next greater nodes
    vector<int> result = nextLargerNodes(head);

    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
