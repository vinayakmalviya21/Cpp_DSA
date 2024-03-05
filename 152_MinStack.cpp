#include <bits/stdc++.h>
using namespace std;

class MinStack {
private:
    vector<pair<int,int>> st;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push_back(make_pair(val,val));
        }
        else{
            st.push_back(make_pair(val,min(val,st.back().second)));
        }
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st.back().first;
    }
    
    int getMin() {
        return st.back().second;
    }

    bool isEmpty() {
        return st.empty();
    }
};

int main()
{
    // * Min stack
    // ! Design a stack that supports push, pop, top, and retrieving the minimum element in constant time. 

    MinStack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.pop();

    while(!s.isEmpty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;

    return 0;
}
