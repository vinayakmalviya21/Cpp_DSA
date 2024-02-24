#include <iostream>
#include <map>
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

// * Remove Duplicates in Unsorted LL
Node *deleteDuplicates(Node *head)
{
    if (head == nullptr)
        return nullptr;

    map<int, bool> seen; // Map to store encountered values
    Node *prev = nullptr;
    Node *curr = head;

    while (curr != nullptr)
    {
        // If the current value is already seen, skip this node
        if (seen.find(curr->val) != seen.end())
        {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        else
        {
            seen[curr->val] = true; // Mark current value as seen
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
}



int main()
{
    Node *head = new Node(4);
    head->next = new Node(2);
    head->next->next = new Node(5);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(2);

    cout << "Original list with duplicates: ";
    printList(head);

    // ! Removing duplicates in Unsorted LL
    head = deleteDuplicates(head);

    cout << "List after removing duplicates: ";
    printList(head);

    return 0;
}

