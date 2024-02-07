# include <iostream>
# include <stdio.h>
# include <stdlib.h>
using namespace std;

// Q1) Find Max of 3 integers

void max_no(int num1, int num2, int num3){
    int a1 = max(num1,num2);
    int ans = max(a1,num3);
    printf("Max is: %d",ans);
    
    
}

int main(){
    max_no(4,5,12);
    return 0;
}
