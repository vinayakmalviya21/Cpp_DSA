#include <iostream>
using namespace std;

class Animal{

    // ! State or Properties
    private:
    int weight;

    public:
    int age;
    string type;

    // ! Default Constructor
    Animal(){
        cout<<"Constructor call"<<endl;
    }

    // ! Parameterised Constructor
    Animal(int age){
        this->age=age;
        cout<<"Parameterised Constructor - I call"<<endl;
    }
    Animal(int age,int weight){
        this->age=age;
        this->weight=weight;
        cout<<"Parameterised Constructor - II call"<<endl;
    }

    // ! Copy Constructor
    Animal(Animal &obj){
        this->age=obj.age;
        this->weight=obj.weight;
        this->type=obj.type;
        cout<<"Copy Constructor call"<<endl;
    }

    // ! ---------------------------
    void eat(){
        cout<<"Eating"<<endl;
    }
    void sleep(){
        cout<<"Sleeping"<<endl;
    }

    int getWeight(){
        return weight;
    }
    void setWeight(int w){
        weight=w;
    }

    // ! Deconstructor
    ~Animal(){
        cout<<"Deconstructor call"<<endl;
    }
};

int main()
{
    // * OOPs - I

    // cout<<"Size of Empty class is: "<<sizeof(Animal)<<endl; // 1

    // ! Object creation

    // ~ Static
    // Animal cat;
    // cat.age=12;
    // cat.type="Lion";
    // cout<<"Age of cat is: "<<cat.age<<endl;
    // cout<<"Type of cat is: "<<cat.type<<endl;
    // cat.eat();
    // cat.sleep();

    // cout<<"Weight of cat is: "<<cat.weight<<endl; // private hai so cant access
    // cat.setWeight(101);
    // cout<<"Weight of cat is: "<<cat.getWeight()<<endl;

    // ~ Dynamic Memory
    // Animal* dog = new Animal;
    // (*dog).age=10;
    // dog->age=10;
    // (*dog).type="Bunny";
    // dog->type="Bunny";
    // dog->eat();
    // dog->sleep();

    // Animal* zebra = new Animal(9);
    // Animal* elephant = new Animal(100,1000);

    // ! Object Copy
    // Animal a(10);
    // Animal c = a;
    // Animal animal1(c);

    Animal d;

    return 0;
}