#include <iostream>
#include <stack>
using namespace std;


// Q1.
class Stack {
public:
    Stack(int capacity) {
        top = -1;
        size = capacity;
        arr[size];
    }

    void push(int value) {
        if (top == size - 1)
            cout << "Stack Overflow";
        else
            arr[++top] = value;
    }

    int pop() {
        if (top == -1) {
            cout << "Stack Underflow";
            return -1;
        }
        return arr[top--];
    }

private:
    int top;
    int size;
    int arr[];
};

int main() {
    Stack myStack(5);
    myStack.push(1);
    myStack.push(2);
    myStack.pop();
    return 0;
}

// Ans : Initially, the code will not compile because the array arr is not initialized properly. It has to be allocated memory using the new keyword. Also, the array arr should be a pointer to an integer. The corrected code is as follows:
class Stack {
public:
    int top;
    int size;
    int *arr;

    Stack(int capacity) {
        this->top = -1;
        this->size = capacity;
        arr = new int[size];
    }

    void push(int value) {
        if (top == size - 1)
            cout << "Stack Overflow";
        else
            arr[++top] = value;
    }


    int pop() {
        if (top == -1) {
            cout << "Stack Underflow";
            return -1;
        }
        return arr[top--];
    }

};

int main() {
    Stack myStack(5);
    myStack.push(1);
    myStack.push(2);
    int ans = myStack.pop();
    cout<<ans<<endl;
    return 0;
}

// Q2. 
class Node {
public:
    int data;
    Node* next;
};

class Stack {
public:
    Stack() {
        top = nullptr;
    }

    void push(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        
    }

    int pop() {
        if (top == nullptr) {
            cout << "Stack Underflow";
            return -1;
        }
        int value = top->data;
        cout << value << endl;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }

private:
    Node* top;
};

int main() {
    Stack myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.pop();
    myStack.pop();
    return 0;
}

// Ans: The code will not compile because the push function does not update the top pointer.It has to move top to newNode .The corrected code is as follows:
class Node {
public:
    int data;
    Node* next;
};

class Stack {
public:
    Stack() {
        top = nullptr;
    }

    void push(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;

        top = newNode;
        
    }

    int pop() {
        if (top == nullptr) {
            cout << "Stack Underflow";
            return -1;
        }
        int value = top->data;
        cout << value << endl;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }

private:
    Node* top;
};

int main() {
    Stack myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.pop();
    myStack.pop();
    return 0;
}

// Q3.
