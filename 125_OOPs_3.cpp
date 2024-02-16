#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() {
        cout << "Speaking" << endl;
    }
};

class Dog : public Animal {
public:
    // ! Override
    void speak() {
        cout << "Barking" << endl;
    }
};

int main() {
    // * OOPs - III
    // ! Runtime polymorphism
    // ~ Operator overriding

    // Dog a;
    // a.speak();

    // ! UpCasting
    // Animal* a = new Dog();
    // a->speak();

    // ! Abstraction i.e. implementation hiding

    return 0;
}
