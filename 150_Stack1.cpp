#include <iostream>
// #include<stack> // ! Include this for stack
using namespace std;

class Stack
{
public:
    int *arr; // Pointer storage
    int top;  // Index of top element
    int size; // Array size

    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        top = -1;
    }

    void push(int data)
    {
        if (size - top > 1)
        {
            // Space available
            top++;
            arr[top] = data;
        }
        else
        {
            // Space not available
            cout << "Stack Overflow" << endl;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            // Stack is empty
            cout << "Stack Underflow" << endl;
        }
        else
        {
            // Stack is not empty
            top--;
        }
    }

    int getTop()
    {
        if (top == -1)
        {
            // Stack is empty
            cout << "No element is there" << endl;
            return 0;
        }
        else
            return arr[top];
    }

    int getSize()
    {
        // No. of valid elements
        return top+1;
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            // Stack is empty
            return true;
        }
        else{
            return false;
        }
    }
};

int main()
{

    // * Stacks - I : LIFO(Last In First Out)

    // ! Creation
    // stack<int> st;

    // ! Insertion
    // st.push(10);
    // st.push(20);
    // st.push(30);
    // st.push(40);

    // ! Remove
    // st.pop();

    // ! Check elememt on top
    // cout<<"Element on top: "<<st.top()<<endl;

    // ! Size of Stack
    // cout<<"Size of stack is: "<<st.size()<<endl;

    // if(st.empty()){
    //     cout<<"Stack is empty"<<endl;
    // }
    // else{
    //     cout<<"Stack is not empty"<<endl;
    // }

    // stack<int> s;
    // s.push(10);
    // s.push(20);
    // s.push(30);
    // s.push(40);

    // ! Printing of stack
    // while(!s.empty()){
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }

    // * Implementing Stack by self

    Stack s(10);

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    while(!s.isEmpty()){
        cout<<s.getTop()<<" ";
        s.pop();
    }
    cout<<endl;

    cout<<"Size of stack: "<<s.getSize()<<endl;

    return 0;
}