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

// ! Approach: Pehle reverse LL and then add from left and ans LL ko reverse krlo
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

void insertAtTail(Node*&head,Node*&tail,int val){
    Node* temp=new Node(val);
    if(head==NULL){
        head=temp;
        tail=temp;
        return;
    }
    else{
        tail->next=temp;
        tail=temp;
    }
}

Node* add(Node* l1,Node* l2){
    int carry=0;
    Node* ansHead=NULL;
    Node* ansTail=NULL;

    while(l1!=NULL && l2!=NULL){

        int sum = carry+l1->val+l2->val;
        int digit=sum%10;
        Node* temp=new Node(digit);
        insertAtTail(ansHead,ansTail,digit);
        carry=sum/10;
        l1=l1->next;
        l2=l2->next;
    }

    while(l1!=NULL){
        int sum = carry+l1->val+l1->val;
        int digit=sum%10;
        insertAtTail(ansHead,ansTail,digit);
        carry=sum/10;
        l1=l1->next;
    }

    while(l2!=NULL){
        int sum = carry+l1->val+l2->val;
        int digit=sum%10;
        insertAtTail(ansHead,ansTail,digit);
        carry=sum/10;
        l2=l2->next;
    }

    while(carry!=0){
        int sum = carry;
        int digit=sum%10;
        insertAtTail(ansHead,ansTail,digit);
        carry=sum/10;
    }
    return ansHead;
}

Node* addTwoNumbers(Node* l1,Node* l2){
    l1 = reverse(l1);
    l2 = reverse(l2);
    Node* ans = add(l1,l2);
    ans = reverse(ans);
    return ans;
} 


int main()
{
    // * Add two numbers in LL

    Node *l1 = new Node(1);
    l1->next = new Node(4);
    l1->next->next = new Node(8);
    printList(l1);

    Node *l2 = new Node(2);
    l2->next = new Node(5);
    l2->next->next = new Node(0);
    printList(l2);

    Node* ans = addTwoNumbers(l1,l2);
    printList(ans);


    return 0;
}
