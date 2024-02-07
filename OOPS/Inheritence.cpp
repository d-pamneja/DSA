#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Bird{
    public:
    int age,weight,nl;
    string color;

    void eat(){
        cout<<"eating"<<endl;
    }

    void fly(){
        cout<<"flying"<<endl;
    }
};

class Sparrow: public Bird{
    public:
        Sparrow(int _age,int _weight,string _color,int _nl){ //Overriding defualt constructor with parameterized constructor
            this->age = _age;
            this->weight = _weight;
            this->color = _color;
            this->nl = _nl;
        }
        
        void grassing(){
            cout<<"grassing"<<endl;
        }
};

class Piegion: public Bird{
    public:
    void guttering(){
        cout<<"guttering"<<endl;
    }
};

int main(){

    Piegion p1;
    p1.fly();

    Sparrow s(2,1,"red",3);
    s.grassing();
    cout<<s.color<<endl;

} 