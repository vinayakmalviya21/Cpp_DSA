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

// * Remove Duplicates in Sorted LL
Node *deleteDuplicates(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *curr = head;
    while (curr != NULL && curr->next != NULL)
    {
        if (curr->val == curr->next->val)
        {
            Node *next_next = curr->next->next;
            delete (curr->next);
            curr->next = next_next;
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}


int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);

    cout << "Original list with duplicates: ";
    printList(head);

    // ! Removing duplicates in Sorted LL
    head = deleteDuplicates(head);

    cout << "List after removing duplicates: ";
    printList(head);

    return 0;
}

