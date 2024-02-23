#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    // Constructor
    Node(int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    // Destructor
    ~Node() {
        int value = this->data;
        // ! Memory free
        if(next != NULL){ 
            delete next;
            next = NULL;
        }
        cout<<"Memory is free for node with data "<<value<<endl;
    }
};


void print(Node* &head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getLength(Node* head){
    int len=0;
    Node* temp = head;
    while(temp!=NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtHead(Node* &tail,Node* &head, int d) {
    if(head == NULL){
        Node* temp = new Node(d);
        head=temp;
        tail=temp;
    }
    else{
        // Create a new node
        Node* temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head=temp;
    }
}

void insertAtTail(Node* &tail,Node* &head, int d) {
    if(tail == NULL){
        Node* temp = new Node(d);
        tail=temp;
        head=temp;
    }
    else{
        // Create a new node
        Node* temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node* &tail, Node* &head, int position, int d) {
    if (position == 1) {
        insertAtHead(tail,head, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while (cnt < position - 1) {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == NULL) {
        insertAtTail(tail,head, d);
        return;
    }

    Node* nodeToInsert = new Node(d);
    
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev= temp;
}

void deleteNode(int position,Node* &head){
    if(position==1){
        Node* temp = head;
        // Deleting first node
        temp->next->prev == NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        Node* curr = head;
        Node* prev = NULL;
        int cnt=1;
        while(cnt<position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        curr->prev = NULL;
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}


int main() {

    // * Doubly Linked List

    // Node* node1 = new Node(5);
    // Node* head = node1;
    // Node* tail = node1;
    // cout<<getLength(head)<<endl;
    // print(head);

    Node* head = NULL;
    Node* tail = NULL;

    print(head);
    insertAtHead(tail,head, 11);
    print(head);
    insertAtHead(tail,head, 13);
    print(head);
    insertAtHead(tail,head, 8);
    print(head);
    insertAtTail(tail,head, 25);
    print(head);
    insertAtPosition(tail,head, 2, 100);
    print(head);
    insertAtPosition(tail,head, 1, 101);
    print(head);
    insertAtPosition(tail,head, 7, 102);
    print(head);

    deleteNode(7,head);
    print(head);

    return 0;
}
