#include <iostream>
// #include<queue> // ! Include this for queue
#include<vector>
using namespace std;

class Queue {
public:
    int *arr; // Pointer storage
    int size; // Array size
    int front; // Index of front element
    int rear; // Index of rear element

    Queue(int size) {
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    void push(int data) {
        if (rear == size) {
            cout << "Q is full" << endl;
        } else {
            arr[rear] = data;
            rear++;
        }
    }

    void pop() {
        if (front == rear) {
            // Queue is empty
            cout << "Q is empty" << endl;
        } else {
            arr[front] = -1;
            front++;
            if (front == rear) {
                front = 0;
                rear = 0;
            }
        }
    }

    int getFront() {
        if (front == rear) {
            // Queue is empty
            cout << "Q is empty" << endl;
            return -1;
        } else
            return arr[front];
    }

    bool isEmpty() {
        if (front == rear) {
            // Queue is empty
            return true;
        } else {
            return false;
        }
    }

    int getSize() {
        return rear - front;
    }
};

int main()
{
    // * Queue
    // ! FIFO(First In First Out) i.e insertion front se hoga and removal rear se hoga
    // ! rear humesha empty location pr hogi
    // ~ Graph aur sliding window k problems m queue use krte h

    // ! Creation
    // queue<int> q;

    // ! Data insertion
    // q.push(5);
    // q.push(15);
    // q.push(25);

    // cout<<"Size of queue: "<<q.size()<<endl;

    // q.pop();
    // cout<<"Size of queue after pop: "<<q.size()<<endl;

    // if(q.empty()){
    //     cout<<"Q is empty"<<endl;
    // }
    // else{
    //     cout<<"Q is non-empty"<<endl;
    // }

    // cout<<"Front element is: "<<q.front()<<endl;

    // * Implementing Queue by self

    Queue q(10);

    q.push(5);
    q.push(15);
    q.push(25);

    cout<<"Size of queue is: "<<q.getSize()<<endl;

    q.pop();
    cout<<"Size of queue after pop: "<<q.getSize()<<endl;

    cout<<"Front element is: "<<q.getFront()<<endl;

    if(q.isEmpty()){
        cout<<"Q is empty"<<endl;
    }
    else{
        cout<<"Q is non-empty"<<endl;
    }

    return 0;
}