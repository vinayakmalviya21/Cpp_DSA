#include <iostream>
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

Node *mergeTwoLists(Node *list1, Node *list2)
{
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;
    
    Node *ans, *tail;

    if (list1->val < list2->val)
    {
        ans = list1;
        tail = list1;
        list1 = list1->next;
    }
    else
    {
        ans = list2;
        tail = list2;
        list2 = list2->next;
    }

    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val < list2->val)
        {
            tail->next = list1;
            tail = list1;
            list1 = list1->next;
        }
        else
        {
            tail->next = list2;
            tail = list2;
            list2 = list2->next;
        }
    }
    if (list1 == NULL)
        tail->next = list2;
    else
        tail->next = list1;
    return ans;
}

int main()
{
    // * Merge Two Sorted LL
    Node *head1 = new Node(1);
    head1->next = new Node(4);
    head1->next->next = new Node(5);

    Node *head2 = new Node(2);
    head2->next = new Node(3);
    head2->next->next = new Node(5);

    cout << "Original list1 : ";
    printList(head1);
    cout << "Original list2 : ";
    printList(head2);

    Node* mergedHead = mergeTwoLists(head1,head2);
    printList(mergedHead);

    return 0;
}