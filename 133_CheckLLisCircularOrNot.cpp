#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    // Constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL; // Initialize prev pointer
    }
};

void insertNode(Node *&tail, int element, int d)
{
    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        Node *curr = tail;
        while(curr->data != element){
            curr = curr->next;
        }

        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(Node *tail)
{
    if (tail == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }
    Node *temp = tail;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail);
    cout << endl;
}

// ! Linked list is circular or not
bool isCircularList(Node* head){
    if(head == NULL){
        return false;
    }
    Node* temp = head->next;
    while(temp != NULL && temp != head){
        temp = temp->next;
    }
    if(temp == head){
        return true;
    }
    return false;
}


int main()
{
    // * Circular Doubly Linked List

    Node *tail = NULL;

    insertNode(tail,5,3);
    print(tail);
    insertNode(tail,3,5);
    print(tail);

    if(isCircularList(tail)){
        cout<<"Linked list is circular"<<endl;
    }
    else{
        cout<<"Linked list is not circular"<<endl;
    }

    return 0;
}
