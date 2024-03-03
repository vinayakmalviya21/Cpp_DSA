#include <iostream>
#include <map>
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

void printList(Node *head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int getLength(Node *head) {
    int len = 0;
    while (head) {
        ++len;
        head = head->next;
    }
    return len;
}

Node *rotateRight(Node *head, int k) {
    if (!head || k == 0) return head; // If head is NULL or k is 0, no rotation needed

    int len = getLength(head);
    k = k % len; // Reduce k to the range [0, len-1]
    if (k == 0) return head; // If k is reduced to 0, no rotation needed

    Node *fast = head;
    Node *slow = head;

    // Move fast pointer to the kth node from the beginning
    for (int i = 0; i < k; ++i) {
        fast = fast->next;
    }

    // Move both pointers until fast reaches the last node
    while (fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    // Update pointers to perform rotation
    fast->next = head;
    head = slow->next;
    slow->next = NULL;

    return head;
}

int main() {
    // Creating the original linked list
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    printList(head);

    int k = 2;

    // * Rotate the linked list
    Node *rotatedHead = rotateRight(head, k);

    // Print the rotated linked list
    printList(rotatedHead);

    return 0;
}
