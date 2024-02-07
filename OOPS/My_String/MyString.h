// Header File - Here, we baiscally declare all our variables and classes. We will define the methods in another file
#ifndef MyString_H
#define MyString_H

# include <iostream>

class MyString
{
    private:
    char *data; //Character Array to store data as an array of characters
    int length;

    public:

    MyString(); // Defualt CTOR

    MyString(const char *str); // Parameterized CTOR

    MyString(const MyString &other); // COPY CTOR


    ~MyString(); // Defualt DTOR


    int size() const; // To give the size of the string

    bool empty() const;// Boolean to check whether string is empty or not

    const char *c_str() const;

    char operator[](int index); // Basically overloading the operator to give out a char when given an index

    int find(const MyString&str)const;

    void myerase(int starting_index,int ending_index);

    void myPop_Back() const;

    void myPush_Back(char &c1) const;

    // Now, we will have to overload the insertion operator (<<) for easy output
    friend std::ostream &operator<<(std::ostream &os,const MyString &str);


};

#endif
