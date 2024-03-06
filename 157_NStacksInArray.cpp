#include <iostream>
using namespace std;

class NStack{
    int *a,*top,*next;
    int n; // no. of stacks
    int size; // Size of main array
    int freeSpot; // tells free space in main array

    public:
    NStack(int _n,int _s):n(_n),size(_s){
        freeSpot = 0;
        a = new int[size];
        top = new int[n];
        next = new int[size];

        for (int i = 0; i < n; i++)
        {
            top[i]=-1;
        }

        for (int i = 0; i < size; i++)
        {
            next[i]=i+1;
        }
        next[size-1]=-1;
    }

    // Push X into nth Stack
    bool push(int X,int n){
        if(freeSpot == -1){
            return false; // stack overflow
        }

        // 1.Find index
        int index = freeSpot;
        // update freespot
        freeSpot = next[index];
        // insert
        a[index] = X;
        // update next
        next[index] = top[n-1];
        // update top
        top[n-1]=index;

        return true; // Push successful
    }

    int pop(int n){
        if(top[n-1]==-1){
            return -1; // stack underflow
        }
        int index = top[n-1];
        top[n-1]=next[index];
        int poppedElement = a[index];
        next[index] = freeSpot;
        return poppedElement;
    }

    ~NStack(){
        delete[] a;
        delete[] top;
        delete[] next;
    }
};

int main()
{
    // * N-stacks in an array

    // int n = 3; // ! No. of stacks
    // int s = 6; // ! Size of array

    NStack s(3,6);
    cout<<s.push(10,1)<<endl;
    cout<<s.push(10,1)<<endl;
    cout<<s.push(10,1)<<endl;
    cout<<s.push(14,2)<<endl;
    cout<<s.push(15,3)<<endl;
    cout<<s.pop(1)<<endl;
    cout<<s.pop(2)<<endl;

    return 0;
}