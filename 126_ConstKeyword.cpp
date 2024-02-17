#include <iostream>
using namespace std;

// * Macros keyword
#define PI 3.14 

float circleArea(float r){
    return PI*r*r;
}

int main()
{
    // * Const Keyword

    // const int x = 10;
    // x=11; // Error dega

    // ! Const with pointers
    // const int *a=new int(2); // Const data,Non-Const pointer
    // int const *a=new int(2); // Same as above line
    // cout<<*a<<endl;
    // *a = 2;
    // cout<<*a<<endl;
    // int b=5;
    // a=&b; // Pointer itself can be reassigned
    // cout<<*a<<endl;

    // ! Const pointer,Non-Const data
    // int *const a=new int(2); 
    // *a = 20;
    // cout<<*a<<endl;
    // int b=5;
    // a=&b; // Nhi chlega,const pointer

    // ! Const pointer,Const data
    // const int *const a=new int(2); 
    // *a = 20; // Nhi chlega,const data
    // cout<<*a<<endl;
    // int b=5;
    // a=&b; // Nhi chlega,const pointer

    // * MACROS Keyword
    cout<<circleArea(60.5)<<endl;

    return 0;
}