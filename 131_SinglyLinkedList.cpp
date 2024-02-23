#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    // Destructor
    ~Node() {
        int value = this->data;
        // ! Memory free
        if(this->next != NULL){ 
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for node with data"<<value<<endl;
    }
};

void insertAtHead(Node* &head, int d) {
    // Create a new node
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d) {
    // Create a new node
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void print(Node* &head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtPosition(Node* &head, Node* &tail, int position, int d) {
    if (position == 1) {
        insertAtHead(head, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while (cnt < position - 1 && temp != NULL) {
        temp = temp->next;
        cnt++;
    }

    if (temp == NULL) {
        // If position is greater than the number of nodes, insert at tail
        insertAtTail(tail, d);
        return;
    }

    Node* nodeToInsert = new Node(d);
    
    nodeToInsert->next = temp->next;
    
    temp->next = nodeToInsert;
}

void deleteNode(int position,Node* &head){
    if(position==1){
        Node* temp = head;
        // Deleting first node
        head = head->next;
        temp->next = NULL;
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
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main() {

    // * Singly Linked List

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    print(head);
    insertAtTail(tail, 12);
    print(head);
    insertAtTail(tail, 15);
    print(head);

    insertAtPosition(head, tail, 4, 22);
    print(head);

    deleteNode(1,head);
    print(head);

    return 0;
}
