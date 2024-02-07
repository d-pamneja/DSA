# include <iostream>
# include <stdlib.h>
# include <cmath>
using namespace std;

// Q1) Display the area of a circle, given the radius
// Ans1) 

void Circle_Area(float radius){
    float pi = 3.14159265;
    float area = (pi*(radius*radius));
    cout << "The area of the circle with radius "<<radius<<" is : "<<area<<endl;
}

// Q2) Factorial of a Number
// Ans2) 

int Factorial(int n){
    if(n<=1){
        return 1;
    }
   int x = n*Factorial(n-1);
   return x;
}

// Q3) All Primes for 1 to N
// Ans3) 

bool check_prime(int n){
    for(int i=2;i<n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

void Primes_List(int n){
    cout<<"The prime numbers between 1 and "<<n<<" are : ";
    for(int i=1;i<n+1;i++){
        if(check_prime(i)){
            cout<<i<<" ";
        }
    }
}

// Q4) Print all digits of an integer
// Ans)

void Int_Digits(int n){
    cout<<"The digits of the integer "<<n<<" are : ";
    while(n>9){
        int rem = n%10;
        n = n/10;
        cout<<rem<<" ";
    }
    cout<<n<<endl;
}

//Q5) Return a Number using Digits
// Ans) 

void Digits_Int(int arr[], int n){
    int num;
    for(int i=0;i<n;i++){
        num = (num*10) + arr[i];
    }
    cout<<"The final number from the digits is : "<<num<<endl;
}

// Q6) Binary Representation of a number
// Ans) 

void Binary_Num(int n){
    int bin = 0;
    int i=0;
    while(n>0){
        int bit = n&1;
        bin += bit*pow(10,i++);
        n = n>>1;
    }
    cout<<bin<<endl;
}

// Q7) Kilometers to Miles
// Ans)

void km_miles(float n){
    float mil = n*1.61;
    cout<<n<<" kilometeres is approximately "<<mil<<" in miles.";
}

// Q8) Celcius from Farenhiet
// Ans) 

void faren_cel(float n){
    float cel = ((n-32)*5)/9;
    cout<<n<<" Farenhiet is approximately "<<cel<<" in celcius.";
}

// Q9) Count set bits of a number
// Ans)

void count_set_bits(int n){
    int num = n;
    int count = 0;
    while(n){
        count += n&1;
        n >>= 1;
    }
    cout<<"The bumber of set bits in the number "<<num<<" are : "<<count<<endl;
}

// Odd or Even using Bits
// Ans)

void even_odd_bits(int n){
    if((n&1) == 1){
        cout<<"The number "<<n<<" is odd.";
    }
    else{
        cout<<"The number "<<n<<" is even.";
    }
}

int main()
{
    // Circle_Area(5.12);

    // cout<<"The factorial for the given number is : "<<Factorial(6)<<endl;

    // Primes_List(13);

    // Int_Digits(1023);

    // int digits[] = {1,2,3,4,5};
    // Digits_Int(digits,5);

    // cout<<"Binary Representation of the given number is : ";
    // Binary_Num(10);

    // km_miles(3);

    // faren_cel(98);

    // count_set_bits(7);

    // even_odd_bits(9);

    return 0;
}
