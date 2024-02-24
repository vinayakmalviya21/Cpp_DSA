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

// ! Approach 1
// Node* sortList(Node* &head){
//     int zeroCount = 0;
//     int oneCount = 0;
//     int twoCount = 0;

//     Node* temp = head;
//     while(temp!= NULL){
//         if(temp->val == 0){
//             zeroCount++;
//         }
//         else if(temp->val == 1){
//             oneCount++;
//         }
//         else if(temp->val == 2){
//             twoCount++;
//         }
//         temp=temp->next;
//     }

//     temp=head;
//     while(temp!=NULL){
//         if(zeroCount!=0){
//             temp->val=0;
//             zeroCount--;
//         }
//         else if(oneCount!=0){
//             temp->val=1;
//             oneCount--;
//         }
//         else if(twoCount!=0){
//             temp->val=2;
//             twoCount--;
//         }
//         temp=temp->next;
//     }
//     return head;
// }

// ! Approach 2
Node *sortList(Node *head)
{
    Node *zeroHead = new Node(0); 
    Node *oneHead = new Node(0);  
    Node *twoHead = new Node(0);  

    Node *zeroTail = zeroHead; 
    Node *oneTail = oneHead;   
    Node *twoTail = twoHead;   

    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->val == 0)
        {
            zeroTail->next = curr;
            zeroTail = zeroTail->next;
        }
        else if (curr->val == 1)
        {
            oneTail->next = curr;
            oneTail = oneTail->next;
        }
        else
        {
            twoTail->next = curr;
            twoTail = twoTail->next;
        }
        curr = curr->next;
    }

    // Combining all lists
    oneTail->next = twoHead->next;
    zeroTail->next = oneHead->next;
    twoTail->next = NULL;

    // New head after sorting
    Node *sortedHead = zeroHead->next;

    // Freeing the dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return sortedHead;
}

int main()
{
    // * Sort 0s,1s,2s in LL
    Node *head = new Node(1);
    head->next = new Node(0);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(2);

    cout << "Original list: ";
    printList(head);

    Node *sortedHead = sortList(head);
    cout << "Sorted list: ";
    printList(sortedHead);

    return 0;
}
