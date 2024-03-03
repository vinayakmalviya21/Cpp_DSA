#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    // Constructor
    Node(int data)
    {
        this->val = data;
        this->next = NULL;
    }
};

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

vector<int> nodesBetweenCriticalPoints(Node *head)
{
    vector<int> ans = {-1, -1};
    Node *prev = head;
    if (!prev)
        return ans;
    Node *curr = head->next;
    if (!curr)
        return ans;
    Node *nxt = head->next->next;
    if (!nxt)
        return ans;

    int firstCP = -1;
    int lastCP = -1;
    int minDist = INT_MAX;
    int i = 1;
    while (nxt)
    {
        bool isCP = ((curr->val > prev->val && curr->val > nxt->val) ||
                     (curr->val < prev->val && curr->val < nxt->val))
                        ? true
                        : false;
        if (isCP && firstCP == -1)
        {
            firstCP = i;
            lastCP = i;
        }
        else if (isCP)
        {
            minDist = min(minDist, i - lastCP);
            lastCP = i;
        }
        ++i;
        prev = prev->next;
        curr = curr->next;
        nxt = nxt->next;
    }
    if (lastCP == firstCP)
    {
        // Only 1 CP found
        return ans;
    }
    else
    {
        ans[0] = minDist;
        ans[1] = lastCP - firstCP;
    }
    return ans;
}

int main()
{

    // * Find min max number between critical points
    // ! A critical point in a linked list is defined as either a local maxima or a local minima.
    // ! Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points. If there are fewer than two critical points, return [-1, -1].

    Node *head = new Node(5);
    head->next = new Node(3);
    head->next->next = new Node(1);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(1);
    head->next->next->next->next->next->next = new Node(2);

    cout << "Original List" << endl;
    printList(head);

    // * Find the minimum and maximum distances between critical points
    vector<int> result = nodesBetweenCriticalPoints(head);

    cout << "Minimum Distance: " << result[0] << endl;
    cout << "Maximum Distance: " << result[1] << endl;

    return 0;
}
