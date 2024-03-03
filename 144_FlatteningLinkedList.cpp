#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node *next;
    Node *child; // Pointer to child list

    // Constructor
    Node(int data) {
        this->val = data;
        this->next = NULL;
        this->child = NULL;
    }
};

// Function to flatten a linked list
Node* flattenList(Node* head) {
    if (!head) return NULL;

    Node* current = head;
    while (current) {
        if (current->child) {
            Node* childHead = flattenList(current->child);
            Node* childTail = childHead;
            while (childTail->next) {
                childTail = childTail->next;
            }
            childTail->next = current->next;
            current->next = childHead;
            current->child = NULL;
        }
        current = current->next;
    }
    return head;
}


// Function to print the linked list
void printList(Node *head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    // Creating a linked list with child lists
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->child = new Node(4);
    head->next->child->next = new Node(5);
    head->next->child->next->child = new Node(6);
    head->next->next->child = new Node(7);
    head->next->next->child->next = new Node(8);
    head->next->next->child->next->next = new Node(9);

    cout << "Original List:" << endl;
    printList(head);

    // * Flatten the list
    head = flattenList(head);

    cout << "Flattened List:" << endl;
    printList(head);

    return 0;
}
