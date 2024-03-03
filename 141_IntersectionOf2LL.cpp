#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node *next;

    // Constructor
    Node(int data) {
        this->val = data;
        this->next = NULL;
    }
};

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head << " "; // Print address instead of value
        head = head->next;
    }
    cout << endl;
}

Node *getIntersectionNode(Node *headA, Node *headB) {
    if (!headA || !headB)
        return NULL;

    // Find the length of both lists
    int lenA = 0, lenB = 0;
    Node *tempA = headA, *tempB = headB;
    while (tempA->next) {
        lenA++;
        tempA = tempA->next;
    }
    while (tempB->next) {
        lenB++;
        tempB = tempB->next;
    }

    // Adjust starting points to make both lists equal in length
    while (lenA > lenB) {
        headA = headA->next;
        lenA--;
    }
    while (lenB > lenA) {
        headB = headB->next;
        lenB--;
    }

    // Traverse both lists until intersection or end is reached
    while (headA && headB) {
        if (headA == headB) // Check if nodes are the same
            return headA;
        headA = headA->next;
        headB = headB->next;
    }

    return NULL; // No intersection found
}

int main() {

    // * Intersection of 2 Linked Lists

    Node *headA = new Node(4);
    headA->next = new Node(1);
    headA->next->next = new Node(8);
    headA->next->next->next = new Node(4);
    headA->next->next->next->next = new Node(5);

    cout << "ListA:" << endl;
    printList(headA);

    Node *headB = new Node(5);
    headB->next = new Node(6);
    headB->next->next = new Node(1);
    headB->next->next->next = headA->next->next; // Connecting ListB to ListA

    cout << "ListB:" << endl;
    printList(headB);

    Node *intersectionNode = getIntersectionNode(headA, headB);
    if (intersectionNode)
        cout << "Intersection Node Address: " << intersectionNode << endl;
    else
        cout << "No intersection found." << endl;

    return 0;
}
