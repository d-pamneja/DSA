#if !defined(BIRD_H)
#define BIRD_H
#include <iostream>

class BIRD{
    public:
    virtual void eat() = 0;
    virtual void fly() = 0;

    // Classes which derive this class WILL HAVE to implement pure virtual functions.
    // Basically here, BIRD has become an interface
};

class Sparrow:public BIRD{
    private:
    void eat(){
        std::cout<<"Sparrow is eating\n";
    }

    void fly(){
        std::cout<<"Sparrow is flying\n";
    }
};

class Eagle:public BIRD{
    private:
    void eat(){
        std::cout<<"Eagle is eating\n";
    }

    void fly(){
        std::cout<<"Eagle is flying\n";
    }
};

#endif