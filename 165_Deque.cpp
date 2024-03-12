#include <iostream>
// #include<deque> // ! Include this for deque
#include <vector>
using namespace std;

class Deque
{
public:
    int *arr;  // Pointer storage
    int size;  // Array size
    int front; // Index of front element
    int rear;  // Index of rear element

    Deque(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    ~Deque()
    {
        delete[] arr;
    }

    void pushRear(int data)
    {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % size))
        {
            cout << "Q is full,can't insert" << endl;
        }
        else if (front == -1)
        {
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = data;
    }

    void pushFront(int data)
    {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % size))
        {
            cout << "Q is full,can't insert" << endl;
            return;
        }
        else if (front == -1)
        {
            front = rear = 0;
        }
        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
        }
        else
        {
            front--;
        }
        arr[front] = data;
    }

    void popFront()
    {
        if (front == -1)
        {
            // Queue is empty
            cout << "Q is empty" << endl;
            return;
        }
        else if (front == rear)
        {
            arr[front] = -1;
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            arr[front] = -1;
            front = 0;
        }
        else
        {
            arr[front] = -1;
            front++;
        }
    }

    void popRear()
    {
        if (front == -1)
        {
            // Queue is empty
            cout << "Q is empty" << endl;
            return;
        }
        else if (front == rear)
        {
            arr[rear] = -1;
            front = rear = -1;
        }
        else if (rear == 0)
        {
            arr[rear] = -1;
            rear = size - 1;
        }
        else
        {
            arr[rear] = -1;
            rear--;
        }
    }

    int getFront()
    {
        if (front == -1)
        {
            cout << "Q is empty" << endl;
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    bool isEmpty()
    {
        if (front == rear)
        {
            // Queue is empty
            return true;
        }
        else
        {
            return false;
        }
    }

    int getSize()
    {
        if (front == -1)
            return 0;
        if (rear >= front)
            return rear - front + 1;
        else
            return size - front + rear + 1;
    }
};

int main()
{
    Deque q(10);

    q.pushRear(5);
    q.pushRear(15);
    q.pushRear(25);

    cout << "Size of queue is: " << q.getSize() << endl;

    q.popFront();
    cout << "Size of queue after pop: " << q.getSize() << endl;

    cout << "Front element is: " << q.getFront() << endl;

    if (q.isEmpty())
    {
        cout << "Q is empty" << endl;
    }
    else
    {
        cout << "Q is non-empty" << endl;
    }

    return 0;
}