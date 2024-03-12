#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseKElements(queue<int> &q,int k){

    if(k<=0 || k>n) return;

    stack<int> st;
    int count=0;
    int n = q.size();
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        st.push(temp);
        count++;

        if(count == k)
            break;
    }

    while(!st.empty()){
        int temp = st.top();
        st.pop();
        q.push(temp);
    }

    count = 0;
    while(!q.empty() && (n-k)!=0){
        int temp = q.front();
        q.pop();
        q.push(temp);
        count++;

        if(count == n-k)
            break;
    }
}

int main()
{
    // * Reverse First K-Elements Of Queue

    queue<int> q;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(12);
    q.push(15);

    int k =3;

    reverseKElements(q,k);

    cout<<"Printing queue: "<<endl;
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}