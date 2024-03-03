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

Node *mergeNodes(Node *head)
{
    if (!head){
        return 0;
    }
    Node *slow = head;
    Node *fast = head->next;
    Node *newLastNode = 0;
    int sum = 0;
    while (fast)
    {
        if (fast->val != 0)
        {
            sum += fast->val;
        }
        else
        {
            slow->val = sum;
            newLastNode = slow;
            slow = slow->next;
            sum = 0;
        }
        fast = fast->next;
    }
    Node *temp = newLastNode->next;

    // Just formed new list
    newLastNode->next = 0;

    // Deleting old list
    while (temp)
    {
        Node *nxt = temp->next;
        delete temp;
        temp = nxt;
    }
    return head;
}

int main()
{

    // * Merge Nodes in B/w Zeroes

    Node *head = new Node(0);
    head->next = new Node(3);
    head->next->next = new Node(1);
    head->next->next->next = new Node(0);
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->next = new Node(5);
    head->next->next->next->next->next->next = new Node(2);
    head->next->next->next->next->next->next->next = new Node(0);

    cout << "Original List" << endl;
    printList(head);

    cout << "List after Merge Nodes" << endl;
    printList(mergeNodes(head));

    return 0;
}
