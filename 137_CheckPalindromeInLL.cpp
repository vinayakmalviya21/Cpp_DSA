#include <bits/stdc++.h>
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

// ! 1. Create an array and then check palindrome
// bool isPalindrome(Node* head) {
//     vector<int> arr;
//     Node* temp = head;
//     while(temp != NULL){
//         arr.push_back(temp->val);
//         temp = temp->next;
//     }  

//     int s = 0, e = arr.size() - 1;
//     while(s <= e){
//         if(arr[s] != arr[e]){
//             return false;
//         }
//         s++, e--;
//     }
//     return true;
// }

// ! 2. Middle element find kro then uske next half part ko reverse krke first part ko compare kro

// ! Function to find middle of a linked list
Node *getMid(Node *head)
{
    Node* slow=head;
    Node* fast=head->next;

    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow=slow->next;
    }
    return slow;
}

Node *reverse(Node *head){
    Node* curr=head;
    Node* prev=NULL;
    Node* next=NULL;
    while(curr!=NULL){
        next = curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

bool isPalindrome(Node* head) {
    if(head==NULL || head->next==NULL){
        return true;
    }
    Node* middle = getMid(head);

    Node* temp=middle->next;
    middle->next=reverse(temp);

    // Compare both halves
    Node*head1=head;
    Node*head2=middle->next;
    while(head2!=NULL){
        if(head1->val != head2->val){
            return false;
        }
        head1=head1->next;
        head2=head2->next;
    }
    temp=middle->next;
    middle->next=reverse(temp);

    return true;
}

int main()
{
    // * Check Palindrome in LL

    Node *head = new Node(1);
    head->next = new Node(4);
    head->next->next = new Node(1);

    if(isPalindrome(head)){
        cout << "Palindrome hai" << endl;
    }
    else{
        cout << "Palindrome nahi hai" << endl;
    }

    return 0;
}
