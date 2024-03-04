#include <iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &s,int target){
    if(s.empty()){
        s.push(target);
        return;
    }
    int topElement = s.top();
    s.pop();
    // ! Recursive call
    insertAtBottom(s,target);
    // ! Backtracking
    s.push(topElement);
}

void reverseStack(stack<int> &s)
{
    if(s.empty()){
        return;
    }

    int target = s.top();
    s.pop();
    // ! Recursive call
    reverseStack(s);
    // ! Backtracking
    insertAtBottom(s,target);
}

int main()
{
    // * Reverse a stack

    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50); 

    reverseStack(s);

    // ! Printing of stack
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}