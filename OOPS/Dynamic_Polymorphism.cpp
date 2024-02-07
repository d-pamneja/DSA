#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Animal{
    public:
    virtual void sound(){
        cout<<"Animal is live."<<endl;
    }
};

class Dog: public Animal{
    public:
    void sound(){
        cout<<"Dog is barking"<<endl;
    }
};

class Cat: public Animal{
    public:
    void sound(){
        cout<<"Cat is meowing"<<endl;
    }
};

void sound(Animal *animal){
    animal->sound(); //polymorphic
}

int main(){
    // Dog *dog = new Dog(); 
    // dog->sound(); // This is how we call methods of instances which are on heap
    // delete dog;

    Animal *animal1 = new Dog(); 
    sound(animal1);

    Animal *animal2 = new Cat(); 
    sound(animal2);

    delete animal1;
    delete animal2;
}
