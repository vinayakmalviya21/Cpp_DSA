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

// * To detect loop in LL

// bool hasCycle(Node* head){
//     Node* temp = head;
//     if(head == NULL){
//         return false;
//     }
//     map<Node*,bool> visited;

//     while(temp!=NULL){
//         // ~ cycle is present
//         if(visited[temp]==true){
//             return true;
//         }
//         visited[temp]=true;
//         temp=temp->next;
//     }
//     return false;
// }

// ! -------------------------------------------

// * Floyd’s Cycle-Finding Algorithm // fast-slow approach // 2 pointers // "tortoise and the hare algorithm"

bool hasCycle(Node *head)
{
    // Create a new node with a default value (assuming Node has a constructor)
    Node *newNode = new Node(0);

    // Check if the head is NULL, and if so, assign the new node to the head
    if (head == NULL)
    {
        head = newNode;
        return false; // You might want to return false if the head is NULL
    }

    // Use two pointers, slow and fast, to check for a cycle
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;       // Move slow one step at a time
        fast = fast->next->next; // Move fast two steps at a time

        // If there's a cycle, the slow and fast pointers will meet at some point
        if (slow == fast)
        {
            return true;
        }
    }

    return false; // If fast reaches the end of the list, there is no cycle
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    // ~ Creating a cycle: 6 -> 3
    head->next->next->next->next->next->next = head->next->next;

    // ! Checking if the list has a cycle
    if (hasCycle(head))
    {
        cout << "The linked list has a cycle." << endl;
    }
    else
    {
        cout << "The linked list does not have a cycle." << endl;
    }

    return 0;
}
