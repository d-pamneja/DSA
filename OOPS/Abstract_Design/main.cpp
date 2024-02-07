#include <iostream>
#include "Bird.h"

using namespace std;

void birdDoesSomething(BIRD *&bird)
{
    bird->eat();
    bird->fly();
    bird->eat();
    bird->fly();
    bird->eat();
    bird->fly();
    bird->eat();
    bird->fly();
    bird->eat();
    bird->fly();
    bird->eat();
    bird->fly();
    bird->eat();
    bird->fly();
}

int main(){
    BIRD *bird = new Sparrow();
    birdDoesSomething(bird);
    return 0;
}