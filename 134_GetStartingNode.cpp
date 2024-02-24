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

Node* hasCycle(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return slow; // Return the intersection node if cycle detected
    }

    return NULL; // If fast reaches the end of the list, there is no cycle
}

Node* getStartingNode(Node* head)
{
    Node* intersection = hasCycle(head);
    if (intersection == NULL)
        return NULL;

    Node* slow = head;

    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}

// * Remove loop in LL
void removeLoop(Node* head) {
    if (head == NULL)
        return;

    Node* startOfLoop = getStartingNode(head);
    if (startOfLoop == NULL)
        return; // No loop found, nothing to remove

    // Find the node just before the start of the loop
    Node* temp = startOfLoop;
    while (temp->next != startOfLoop)
        temp = temp->next;

    // Break the loop by setting the next pointer of the last node in the loop to NULL
    temp->next = NULL;
}

int main() {
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    // Creating a cycle: 6 -> 3
    head->next->next->next->next->next->next = head->next->next;

    // Checking if the list has a cycle
    if (hasCycle(head)) {
        cout << "The linked list has a cycle." << endl;

        // * Starting Node 
        Node* startingNode = getStartingNode(head);
        cout << "Starting node of the cycle: " << startingNode->val << endl;

        // * Remove the loop
        removeLoop(head);

        // Check if the loop is successfully removed
        if (!hasCycle(head)) {
            cout << "Loop removed successfully." << endl;
        } else {
            cout << "Failed to remove the loop." << endl;
        }
    } else {
        cout << "The linked list does not have a cycle." << endl;
    }

    return 0;
}
