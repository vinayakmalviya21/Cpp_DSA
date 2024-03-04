#include <iostream>
#include<stack>
using namespace std;

void insertSorted(stack<int> &s,int target){
    if(s.empty()){
        s.push(target);
        return;
    }
    if(s.top() >= target){
        s.push(target);
        return;
    }

    int topElement = s.top();
    s.pop();
    // ! Recursive call
    insertSorted(s,target);
    // ! Backtracking
    s.push(topElement);
}

void sortStack(stack<int> &s){
    if(s.empty()){
        return;
    }

    int topElement = s.top();
    s.pop();
    // ! Recursive call
    sortStack(s);
    // ! Backtracking
    insertSorted(s,topElement);
}

int main()
{
    // * Sort a stack 

    stack<int> s;
    s.push(10);
    s.push(50);
    s.push(90); 
    s.push(70);
    s.push(30);

    sortStack(s);

    // ! Printing of stack
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}