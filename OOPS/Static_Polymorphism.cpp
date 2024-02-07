#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Vector{
    int x,y;

    public:

    Vector(int _x, int _y):x(_x),y(_y){}; // Constructor using Initialisation List

    void display(){
        cout<<"x: "<<x<<" "<<"y: "<<y<<endl;
    }

    int getX(){
        return x;
    }

    int getY(){
        return y;
    }

    void operator+(Vector &v2){ // addition answer should be stored in v1, hence we use OPERATOR CONSTRUCTOR OVERRIDING
        cout<<"Overrided addition constructor has been called"<<endl;
        this->x = this->x +  v2.x;
        this->y = this->y +  v2.y;
    }

    void operator-(Vector &v2){ // subtraction answer should be stored in v1, hence we use OPERATOR CONSTRUCTOR OVERRIDING
        cout<<"Overrided subtraction constructor has been called"<<endl;
        this->x = this->x -  v2.x;
        this->y = this->y -  v2.y;
    }

    void operator++(){
        cout<<"Overrided ++ constructor has been called"<<endl;
        this->x++;
        this->y++;
    }
};

int main(){
    Vector v1(4,5);
    Vector v2(3,8);
    Vector v3(1,2);

    // v1 + v2;
    // v1.display();

    // v2 - v1;
    // v2.display();

    v1+v2;
    v1.display();
}