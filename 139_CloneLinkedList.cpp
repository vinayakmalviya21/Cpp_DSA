#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node *next;
    Node *random;

    // Constructor
    Node(int data) {
        this->val = data;
        this->next = NULL;
        this->random = NULL;
    }
};

void printList(Node *head) {
    while (head != NULL) {
        cout << head->val;
        if (head->random)
            cout << "(" << head->random->val << ")";
        cout << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

void insertAtTail(Node *&head, Node *&tail, int d) {
    Node *newNode = new Node(d);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

Node *copyList(Node *head) {
    if (head == NULL)
        return NULL;

    unordered_map<Node *, Node *> oldToNewNode;

    // Clone the list with next pointers
    Node *cloneHead = NULL;
    Node *cloneTail = NULL;
    Node *curr = head;
    while (curr != NULL) {
        insertAtTail(cloneHead, cloneTail, curr->val);
        oldToNewNode[curr] = cloneTail;
        curr = curr->next;
    }

    // Update random pointers
    curr = head;
    Node *cloneCurr = cloneHead;
    while (curr != NULL) {
        cloneCurr->random = oldToNewNode[curr->random];
        curr = curr->next;
        cloneCurr = cloneCurr->next;
    }

    return cloneHead;
}

int main() {

    // * Clone a Linked List with next and random pointer

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // ! Setting random pointers for demonstration
    head->random = head->next->next;     // 1 -> 3
    head->next->random = head->next;     // 2 -> 2
    head->next->next->random = head;     // 3 -> 1
    head->next->next->next->random = head->next; // 4 -> 2
    head->next->next->next->next->random = head->next->next; // 5 -> 3

    cout << "Original List:" << endl;
    printList(head);

    Node *clonedList = copyList(head);
    cout << "Cloned List:" << endl;
    printList(clonedList);

    return 0;
}
