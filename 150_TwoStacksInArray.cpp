#include <iostream>
using namespace std;

class Stack
{
public:
    int *arr;
    int size;
    int top1;
    int top2;

    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        top1 = -1;
        top2 = size;

        for (int i = 0; i < size; ++i)
        {
            arr[i] = 0;
        }
    }

    void push1(int data)
    {
        if (top2 - top1 == 1)
        {
            // Space not available
            cout << "Stack Overflow in stack1" << endl;
        }
        else
        {
            // Space available
            top1++;
            arr[top1] = data;
        }
    }

    void pop1()
    {
        if (top1 == -1)
        {
            // Stack is empty
            cout << "Stack Underflow in stack1" << endl;
        }
        else
        {
            // Stack is not empty
            arr[top1]=0;
            top1--;
        }
    }

    void push2(int data)
    {
        if (top2 - top1 == 1)
        {
            // Space not available
            cout << "Stack Overflow in stack2" << endl;
        }
        else
        {
            // Space available
            top2--;
            arr[top2] = data;
        }
    }

    void pop2()
    {
        if (top2 == -1)
        {
            // Stack is empty
            cout << "Stack Underflow in stack2" << endl;
        }
        else
        {
            // Stack is not empty
            arr[top2]=0;
            top2++;
        }
    }

    void print()
    {
        cout << endl;
        cout << "Top1: " << top1 << endl;
        cout << "Top2: " << top2 << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{

    // * Two Stacks in an Array

    Stack s(10);

    s.push1(10);
    s.print();
    s.push1(20);
    s.print();
    s.push1(30);
    s.print();
    s.push1(40);
    s.print();
    s.push1(50);
    s.print();

    s.push2(60);
    s.print();
    s.push2(70);
    s.print();
    s.push2(80);
    s.print();
    s.push2(90);
    s.print();
    s.push2(100);
    s.print();

    return 0;
}