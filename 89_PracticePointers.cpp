#include <iostream>
using namespace std;

int main()
{

    // ! Problem 1

    // int a=7;
    // int b=17;
    // int *c = &b;
    // *c = 7;
    // cout<<a<<" "<<b<<" "<<c<<endl; //~ 7 7 random
    

    // ! Problem 2

    // int *ptr = 0;
    // int a=10;
    // *ptr = a;
    // cout<<*ptr<<endl;  //~ Runtime error

    // ! Problem 3

    // char ch = 'a';
    // char* ptr = &ch;
    // ch++;
    // cout<<*ptr<<endl;  //~ b

    // ! Problem 4

    int a = 7;
    int* c = &a;
    c = c + 1;
    cout<<a<<" "<<*c<<endl;  //~ 7 random


    

    return 0;
}