#include <iostream>
using namespace std;

// class Animal{
// public:
//     int age;
//     string type;

//     void eat()
//     {
//         cout << "Eating" << endl;
//     }
// };

// ! Inheritance
// class Dog:public Animal{
// };

// class Cat:private Animal{
// };

// class Lion:protected Animal{
// };

// ! Polymorphism
// ~ Function Overloading
// class Maths{
//     public:
//     int sum(int a,int b){
//         return a+b;
//     }
//     int sum(int a,int b,int c){
//         return a+b+c;
//     }
// };

// ~ Operator Overloading
class Param{
    public:
    int val;
    void operator+(Param obj2){
        int value1=this->val;
        int value2=obj2.val;
        cout<<(value2-value1)<<endl;
    }
};

int main()
{

    // * OOPs-II

    // ! Encapsulation i.e. data hiding

    // ! Inheritance i.e.  parent class se properties inherit krna
    // Dog d1;
    // d1.eat();

    // ! Polymorphism i.e. existing in multiple forms
    // ~ Function Overloading
    // Maths obj;
    // cout<<obj.sum(2,3,4);

    // ~ Operator Overloading
    Param obj1,obj2;
    obj1.val=7;
    obj2.val=12;
    // this should print difference b/w them
    obj1+obj2;

    return 0;
}