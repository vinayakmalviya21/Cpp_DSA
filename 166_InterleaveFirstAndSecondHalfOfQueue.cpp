#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int> &q){

    int n = q.size();
    if(n==0) return;
    int k = n/2;
    int count = 0;
    queue<int> q2;

    while(!q.empty()){
        int temp = q.front();
        q.pop();
        q2.push(temp);
        count++;

        if(count == k)
            break;
    }

    while(!q.empty() && !q2.empty()){
        int first = q2.front();
        q2.pop();

        q.push(first);

        int second = q.front();
        q.pop();

        q.push(second);
    }

    if(n&1){
        // ! if odd queue rhi toh
        int element = q.front();
        q.pop();

        q.push(element);
    }
}

int main()
{
    // * Interleave First And Second Half Of Queue
    // ! Input: 10 20 30 40 50 60 70 80
    // ! Output: 10 50 20 60 30 70 40 80

    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);

    interleaveQueue(q);

    cout<<"Printing queue: "<<endl;
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}