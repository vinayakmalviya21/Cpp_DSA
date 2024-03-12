#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseQueue(queue<int> &q){
    stack<int> st;

    while(!q.empty()){
        int element = q.front();
        q.pop();

        st.push(element);
    }

    while(!st.empty()){
        int element = st.top();
        st.pop();

        q.push(element);
    }
}

int main()
{
    // * Reverse queue

    queue<int> q;
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);

    reverseQueue(q);

    cout<<"Printing queue: "<<endl;
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}