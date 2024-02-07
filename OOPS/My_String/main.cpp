#include <iostream>
#include <string>
#include "MyString.h"

using namespace std;

int main(){
    MyString s("Dhruv Pamnejas");
    // MyString s1 = " is studying DSA";
    // cout<<s;
    // cout<<s1<<endl;

    // cout<<s[0]<<endl;

    // MyString s2 = "DSsi";
    // cout<<s1.find(s2)<<endl;

    // string x = "DSISIS";
    // string x1 = "DSI";
    
    // cout<<x<<endl;

    s.myPop_Back();
    cout<<s<<endl;
    return 0;
}