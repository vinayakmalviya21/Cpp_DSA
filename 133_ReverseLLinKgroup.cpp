#include<iostream>
using namespace std; 

class Node
{
public:
    int val;
    Node *next;
    
    // Constructor
    Node(int data) {
    this->val = data; 
    this->next = NULL;
}
};

// Function to print the linked list
void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// ! Function to reverse K-group of the linked list
Node* reverseKGroup(Node* head, int k) {
        if (head == nullptr) {
            return nullptr;
        }
        
        Node* curr = head;
        int count = 0;
        
        // Count the number of nodes in the current group
        while (curr != nullptr && count < k) {
            curr = curr->next;
            count++;
        }
        
        // If the current group has fewer than k nodes, return head (no need to reverse)
        if (count < k) {
            return head;
        }
        
        // Reverse the current group of k nodes
        Node* prev = nullptr;
        curr = head;
        count = 0;
        while (curr != nullptr && count < k) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            count++;
        }
        
        // Recursively reverse the next group of k nodes
        if (curr != nullptr) {
            head->next = reverseKGroup(curr, k);
        }
        
        return prev; 
    }

int main()
{
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original list: ";
    printList(head);

    // Reversing the linked list in groups of 3 nodes
    int k = 3;
    head = reverseKGroup(head, k);

    cout << "Reversed list: ";
    printList(head);

    return 0;
}
