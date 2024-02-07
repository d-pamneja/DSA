# include <iostream>
# include <vector>

// Swap using Arthematic
void arthSwap(int a, int b){
    a = a + b;
    b = a - b;
    a = a - b;
}

// Swap uisng XOR - Yeh sabse fast process hai
void XORSwap(int a, int b){
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    // DRY RUN
    // a = 2; b = 3;
    // a = 2^3;
    // b = 2^3^3; -> b = 2;
    // a = 2^3^2; -> a = 3;
}

