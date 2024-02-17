#include <iostream>
using namespace std;

class abc{
    public:
    static int x,y;

    // ! Static member function
    static void print(){
        cout<<x<<" "<<y<<endl;
    }
};

int abc::x;
int abc::y;

int main()
{
    // * Static keyword
    abc obj1;
    obj1.x=1;
    obj1.y=2;
    obj1.print();
    abc obj2;
    obj2.x=3;
    obj2.y=4;
    obj1.print();  // x and y ki value change hojayegi because wo puri class k liye ek hi x and y hai
    obj2.print();


    return 0;
}