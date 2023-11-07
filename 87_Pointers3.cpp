#include <iostream>
using namespace std;

void util(int* p){
    // p = p + 1; --> ye copy banayega
    *p = *p + 1; // --> ye main wale function m     change krega
}

int main()
{
    // * Double Pointers

    // int a = 2;
    // int* p = &a;
    // int** q = &p;

    // cout<<a<<endl;
    // cout<<&a<<endl;
    // cout<<p<<endl;
    // cout<<&p<<endl;
    // cout<<*p<<endl;
    // cout<<q<<endl;
    // cout<<&q<<endl;
    // cout<<*q<<endl;
    // cout<<**q<<endl;

    int a = 5;
    int* p = &a;

    cout<<"Before"<<endl;
    cout<<a<<endl;
    cout<<p<<endl;
    cout<<*p<<endl;

    util(p);

    cout<<"After"<<endl;
    cout<<a<<endl;
    cout<<p<<endl;
    cout<<*p<<endl;



    return 0;
}