// Main File - Here, we will define the methods which are decalred in the header class
#include "MyString.h"
#include <cstring>

// Definitions of all the functions declared in MyString.h

MyString::MyString(){ // This means ki MyString class ke MyString() yaani default constructor ko yaha define karo - which is defiend in MyString.h
    data = new char[1];
    length = 0;
    data[0] = '\0'; //Basically here, we are initialising an empty string as a char array and storing the null/stop char in it
}

MyString::MyString(const char  *str){ // This means ki MyString class ke MyString(const char*str) yaani parameterised constructor ko yaha define karo - which is defiend in MyString.h
    data = new char[strlen(str)+1];
    length = strlen(str);
    strcpy(data,str); //Basically, jo bhi data str see aa raha hai usko copy kar do data mein 
}


MyString::MyString(const MyString &other){ // This means ki MyString class ke MyString(const MyString &other) yaani copy constructor ko yaha define karo - which is defiend in MyString.h
    data = new char[other.length + 1];
    length = other.length;
    strcpy(data,other.data); //Basically, jo bhi other ka data hai (other.data) aa raha hai usko copy kar do data mein 
}

int MyString::size() const{
    return length;
}

bool MyString::empty() const{
    return length==0;
}

const char *MyString::c_str() const{
    return data;
}

char MyString::operator[](int index){
    if(index >=length){
        return '\0';
    }

     return data[index];

}

std::ostream &operator<<(std::ostream &os,const MyString &str){
    os<<str.c_str();
    return os;
}

int MyString::find(const MyString&str) const{
    if(str.length > length){
        return -1;
    }
     
    for(int i=0;i<=length - str.length;i++){ // If we do not find it till that index after which only str.length chars are left, it is OBVIO ki iske baad no need to check
        int j;
        for(j=0;j<str.length;j++){ // Check this loop again with a dry run prolly
            if(data[i+j] != str.data[j]){
                break;
            }
        }

        if(j == str.length){
            return i;
        }
    }

    return -1;
}

// void MyString::myerase(int starting_index,int ending_index){
//     for(int i=starting_index;i<ending_index;i++){
//         cout<<data[i];
//     }
// }

void MyString::myPop_Back() const{
    data[length-1] = '\0';
}

// void MyString::myPush_Back(char &c1) const{
//     data = new char[length+1];
//     data =
// };

MyString::~MyString(){
    delete[] data; //Basically, delete data which has been dynamically allocated
}

