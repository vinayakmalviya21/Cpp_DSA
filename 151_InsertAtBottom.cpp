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

int main()
{
    // * Insert at bottom

    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    if(s.empty()){
        cout<<"Stack is empty"<<endl;
        return 0;
    }
    int target = s.top();
    s.pop();

    insertAtBottom(s,target);

    // ! Printing of stack
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }

    return 0;
}