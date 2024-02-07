#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person{
    public:
    void exists(){
        cout<<"Person exists."<<endl;
    }
};

class Teacher:virtual public Person{
    public:
    void teach(){
        cout<<"Teacher teaches."<<endl;
    }
};

class Researcher:virtual public Person{
    public:
    void researches(){
        cout<<"Researcher researches."<<endl;
    }
};


class Proffesor: public Teacher, public Researcher{
     public:
     void bores(){
        cout<<"Proffesor bores."<<endl;
     }
};

int main(){

    Proffesor p1;
    p1.teach();
    p1.researches();
    p1.bores();

    // Diamond Probelm : Now, we can resolve ambigious inheritence via two methdos -> Scope Resolution (bekar method) and virtual
    
    // // Scope Resolution
    // p1.Teacher::exists(); // Matlab ki humne p1 ko specially kaha ki teacher wall awalk use kar le
    // p1.Researcher::exists(); // Matlab ki humne p1 ko specially kaha ki teacher wall awalk use kar le

    // // Virtual (Dono ke common elements ko ek hi kar de voh bhi RUNTIME pe) - For this, we will have to mention while inheriting the class itself
    // p1.exists();

     

    return 0;
}