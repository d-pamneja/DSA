# include <iostream>
# include <stdlib.h>
# include <cmath>
#include <cstdio>

using namespace ::std;

#define PI 3.145946527 // Basically, jaha jaha PI likha hai code mein, waha par 3.1459465 utha kar daal deta hai BEFORE COMPLIING the code. This is done by the preprocessor. This does not even take any memory and improves code ki readability
#define MAXX(x,y) (x>y?x:y)

class abc{
    int x; //Mutable basically allows us to override the 'const' function if the need arises. 
    int *y;
    int z;

    public:
        // abc(){
        //     x = 0;
        //     y = new int(0);
        // }

        // abc(int _x, int _y, int _z = 0){ // Here, _z has a default value i.e. if we do not give it in our instance, it will give zero automatically. Default arguments humesha rightmost pe rakhni hoti hai
        //     x = _x;
        //     y = new int(_y);
        //     z = _z;
        // }

        // Using Initialisation List -> does the same work as a regular constructor
        abc(int _x, int _y, int _z = 0):x(_x),y(new int(_y)),z(_z){};

        int getX() const{ // Const here implies ki abh yeh kabhi modify nahi karega kisi value ko, untill and unless voh value mutable type ki ho
            return x;
        }

        int getY() const {
            return *y;
        }

        void setX(int _value){
            x = _value;
        }

        void setY(int _value){
            *y = _value;
        }

        int getZ() const {
            return z;
        }

        void setZ(int _value){
            z = _value;
        }

    ~abc(){
        cout<<"dtor has been called"<<endl;
        delete y;
    }
};

void printABC(const abc &a){ // Here, since we have decalred this function to expect a const, we cannot pass any call inside this which is not a const itself
    cout<<a.getX()<<" "<<a.getY()<<" "<<a.getZ()<<endl; // That is, it will give error iff getX(), getY() or getZ() is not a constant method.
}


class abc2{
    public:
    static int x, y; // We do so when we want to share the same value/variable to all instances of this class

    static void print(){ // Static mein sirf static variables hi mention kar sakte ho. Yaha, there is no this pointer
        cout<<"I am in Static : "<<__FUNCTION__<<endl;
    }

};

// Static variable must be initialised like this outside the class, as they are supossed to be used by all instances of our class
int abc2::x;
int abc2::y;

class ghy{
    public:
    int x;
    int *y;

    ghy(int _x,int _y):x(_x),y(new int(_y)){};

    void print(){
        printf("X is %d\nY is %p\nContent of Y is %d.",x,y,*y);
    }

    ~ghy(){
        cout<<"dtor has been called"<<endl;
        delete y;
    }
    
};

class ghy2{
    public:
    int x;
    int *y;

    ghy2(int _x,int _y):x(_x),y(new int(_y)){};

    ghy2(const ghy2&obj){
        x = obj.x;
        y = new int(*obj.y); // Iska matlab jo bhi obj y ke pointer pe pada hai, uski copy alag jagah pe bana do
    }

    void print(){
        printf("X is %d\nY is %p\nContent of Y is %d.",x,y,*y);
    }

    ~ghy2(){
        cout<<"dtor has been called"<<endl;
        delete y;
    }
    
};

class box{
    int width;
    box(int _width):width(_width){}; //ctor
    
    public:

    int getWidth() const{
        return width;
    }

    void setWidth(int _width){
        width = _width;
    }

    friend class boxfactory; // Iska matlab hai ki sirf voh class jiska naam 'boxfactory' hai voh hi ek naya box initialise kar sakti hai

};

class boxfactory{
    static int count;
    
    public:
    box getabox(int _w){
        ++count;
        return box(_w);
    }

    void getcount(){
        cout<<"Total number of boxes made : "<<count<<endl;
    }

};

class trial{
    private:
    int x11;

    public:
    trial(int _val):x11(_val){};

    int getX() const{return x11;}
    void setX(int _val){x11=_val;}

    friend class mini_trial;
    friend void printViaFunction(const trial&g);

};

class mini_trial{
    public:
    void printTrial(const trial&g){
        cout<<g.getX()<<endl;
    }

    void printPrivate(const trial&g){
        cout<<g.x11<<endl;
    }

    void printViaFunction(const trial &g){
        cout<<g.x11<<endl;
    }
};

int boxfactory::count=0;

int main()
{
    // // Declaring a const variable
    // const int x = 5;
    // cout<<x<<endl;

    // // 1. Const with pointers (Const DATA ka Non Const pointer)
    // const int *a = new int(2); // Here, we cannot re assign the content of the data i.e. the data is constant. However, the pointer pointing  to this can be changed i.e. 'a' can be pointed elsewhere
    // int const *c = new int(3);
    // // Basically, if we write const before *, the content/data is Constant but pointer is modifiable i.e. it can point elsewhere
    // cout<<*a<<endl; 
    // cout<<*c<<endl; 

    // int b = 20;
    // a = &b;
    // cout<<*a<<endl;

    // // 2. Const with pointers (Non Const DATA ka Const pointer)
    // int *const j = new int(30);
    // cout<<*j<<endl;

    // *j = 40;
    // cout<<*j<<endl;

    // // Basically, if we write const after *, the pointer is Constant but data/content is modifiable

    // // 3. Const Data & Const Pointer
    // const int *const k = new int(55);
    // cout<<*k<<endl;

    // // Here, we write const twice. This ensure ki kuch bhi na change ho

    // // 4. Const in class
    // abc x1(25,11);
    // printABC(x1);

    // abc x2(25,11,89);
    // printABC(x2);

    // // 5. Using MACROS
    // cout<<" Pie into 2 is : "<<PI*2<<endl;
    // cout<<" Pie into 3 is : "<<PI*3<<endl;
    // cout<<" Pie into 4 is : "<<PI*4<<endl;
    // cout<<" Pie into 5 is : "<<PI*5<<endl;
    // cout<<" Pie into 6 is : "<<PI*6<<endl;
    // cout<<" Pie into 7 is : "<<PI*7<<endl;

    // cout<<"Max of 5 and 4 is : "<<MAXX(4,5)<<endl;
    // cout<<"Max of 7 and 1 is : "<<MAXX(7,1)<<endl;
    // cout<<"Max of 0 and 4 is : "<<MAXX(4,0)<<endl;
    // return 0;

    // // 6. Static Variables
    // abc2 obj1;
    // abc2::x = 10;
    // abc2::y = 20;

    // abc2::print();

    // // 7. Shallow Vs Deep Copy
    // ghy ob1(5,4);
    // cout<<"Object 1 ka print"<<endl;
    // ob1.print();
    // cout<<endl;
    // cout<<endl;
    // ghy ob2 = ob1; // yeh hai SHALLOW COPY. This uses the default copy constructor, jo exactly wahi par point kar deta hai. Toh, any changes in obj2 will change obj1 also, kyunki dono jagah same location ko hi point kar rahi hai
    // cout<<"Object 2 (shallow copy of ob1) ka print"<<endl;
    // ob2.print();
    // cout<<endl;
    // cout<<endl;

    // ghy2 ob11(5,4);
    // cout<<"Object 11 ka print"<<endl;
    // ob11.print();
    // cout<<endl;
    // cout<<endl;
    // ghy2 ob22 = ob11; // Upar walle ka ekdum ulta hota hai DEEP COPY. Yeh humme specifically likhna padega
    // cout<<"Object 22 (Deep Copy of ob11) ka print"<<endl;
    // ob22.print();
    // cout<<endl;
    // cout<<endl;
    

    // *ob22.y = 40;

    // cout<<"Object 11 ka print (after change in ob22)"<<endl;

    // ob11.print();
    // cout<<endl;
    // cout<<endl;
    // cout<<"Object 11 ka print"<<endl;

    // cout<<"Object 22 ka print, after changes"<<endl;
    // ob22.print();
    // cout<<endl;
    // cout<<endl;

    // 8. Can constructor be made private??
    // box b(5);
    // cout<<b.getWidth()<<endl;
    // b.setWidth(10);
    // cout<<b.getWidth()<<endl;

    // Now, YES. We can make a constructor private. Par phir kuch access nahi kar paaogay, you cannot create an instance, nor can we get/change it.
    // Suppose we have a situation ki we can only create a box through box factory. Toh we will use the box factory class
    // boxfactory bfact;

    // box b1 = bfact.getabox(5);
    // box b2 = bfact.getabox(10);
    // box b3 = bfact.getabox(15);

    // cout<<"Box 1 created via Box Factory Width : ";
    // cout<<b1.getWidth()<<endl;

    // cout<<"Box 2 created via Box Factory Width : ";
    // cout<<b2.getWidth()<<endl;

    // cout<<"Box 3 created via Box Factory Width : ";
    // cout<<b3.getWidth()<<endl;

    // b3.setWidth(10);
    // cout<<"Box 3 new Width : ";
    // cout<<b3.getWidth()<<endl;

    // bfact.getcount();

    // 9. Friend

    trial element(5);
    mini_trial ele;

    ele.printTrial(element);
    ele.printPrivate(element);
    ele.printViaFunction(element);

    // Thus, by using friend in parent class, we can access private elements of parent class from the child class
    // Also, we can make a particular function also a friend
    return 0;


}
