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
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

Node *findMid(Node *head)
{
    Node* slow=head;
    Node* fast=head->next;

    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow=slow->next;
    }
    return slow;
}

Node *merge(Node* left,Node* right){
    if(left==NULL)
        return right;

    if(right==NULL)
        return left;

    Node* ans = new Node(-1);
    Node* temp = ans;

    while(left!=NULL && right!=NULL){
        if(left->val < right->val){
            temp->next=left;
            temp=left;
            left=left->next;
        }
        else{
            temp->next=right;
            temp=right;
            right=right->next;
        }
    }

    while(left!=NULL){
        temp->next=left;
        temp=left;
        left=left->next;
    }

    while(right!=NULL){
        temp->next=right;
        temp=right;
        right=right->next;
    }

    ans=ans->next;
    return ans;
}

Node *mergeSort(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* mid = findMid(head);

    Node* left = head;
    Node* right = mid->next;
    mid->next=NULL;

    left=mergeSort(left);
    right=mergeSort(right);

    Node* result = merge(left,right);
    return result;
}

int main() {

    // * Merge Sort in Linked List 

    Node *head = new Node(30);
    head->next = new Node(20);
    head->next->next = new Node(5);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(15);

    cout << "Original List:" << endl;
    printList(head);

    Node *finalList = mergeSort(head);
    cout << "Merged List:" << endl;
    printList(finalList);

    return 0;
}
