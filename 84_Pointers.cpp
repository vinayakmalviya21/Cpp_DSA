#include <iostream>
using namespace std;

int main()
{

    // * Pointers

    // ! Address of operator --> &

    // int a=5;
    // int b=5;
    // cout<<"Value of a: "<<a<<endl;

    // cout<<"Address of a: "<<&a<<endl;
    // cout<<"Address of b: "<<&b<<endl;

    // ! Pointers

    // int a=5;
    // Pointer create
    // int* ptr = &a; // ptr is pointer to integer data
    // (*) ---> dereference operator
    // cout<<"Address of a: "<<&a<<endl;
    // cout<<"Value of ptr: "<<ptr<<endl;
    // cout<<"Value stored at location in ptr: "<<*ptr<<endl;
    // cout<<"Address of ptr: "<<&ptr<<endl;

    // int a = 5;
    // int* ptrA = &a;
    // cout<<"Size of ptrA: "<<sizeof(ptrA)<<endl;

    // char ch = 'b';
    // char* ptrB = &ch;
    // cout<<"Size of ptrB: "<<sizeof(ptrB)<<endl;   

    // double dtr = 5.03;
    // double* ptrC = &dtr;
    // cout<<"Size of ptrC: "<<sizeof(ptrC)<<endl;

    // ! Null Pointer
    int* ptr = nullptr;
    cout<<*ptr<<endl;

    return 0;
}