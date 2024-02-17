#include <iostream>
using namespace std;

int x=2; // * Global Variable

int main()
{
    // * Local and Global Variable

    x=4; // global x
    int x=20; // local to main() function
    cout<<"Accessing local variable: "<<x<<endl;
    cout<<"Accessing global variable: "<<::x<<endl;

    {
        int x=50;
        cout<<"Accessing most recent local variable: "<<x<<endl;
    }

    return 0;
}