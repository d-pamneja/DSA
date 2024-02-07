#include <iostream>
#include <stack>
using namespace std;

/// V.V.V.V.V.V IMPORTANT!!!!
// This is a very important question and is asked in many interviews.
// The question is to implement N Stacks in a single array.
// The array is divided into N stacks and each stack has its own top and next pointer.
// The next pointer is used to point to the next free space in the array.
// The top pointer is used to point to the top of the stack.
// The free space is used to store the index of the next free space in the array.
// The top pointer is used to store the index of the top of the stack.
// The next pointer is used to store the index of the next element in the stack.


class NStacks{
    
    int *a, *top, *next;
    int n; // Number of stacks
    int size; // Total size of array
    int freespot; // Free space in array

    public:
        NStacks(int _n, int _size): n(_n),size(_size){
            a = new int[size];
            top = new int[n];
            next = new int[size];
            freespot = 0;

            for(int i=0; i<n; i++){
                top[i] = -1;
            }

            for(int i=0;i<size-1;i++){
                next[i] = i+1;
            }
            next[size-1] = -1;
        };

        bool push(int X, int m){ // Push X into M Stack
            if(freespot == -1){
                cout << "Stack Overflow" << endl;
                return false;
            }

            // 1. Find Index of free spot
            int index = freespot;

            // 2. Update free spot
            freespot = next[index];

            //3. Insert into Array
            a[index] = X;

            //4. Update next
            next[index] = top[m-1];

            //5. Update top
            top[m-1] = index;

            return true;
        }

        int pop(int m){ // Pop from Mth Stack
            if(top[m-1]==-1){
                cout << "Stack Underflow" << endl;
                return -1;
            }

            // 1. Find Index of top
            int index = top[m-1];

            // 2. Update top
            top[m-1] = next[index];

            // 3. Return popped element
            int popped = a[index];

            // 4. Update next
            next[index] = freespot;

            // 5. Update free spot
            freespot = index;

            return popped;

        };

        ~NStacks(){ // Destructor
            delete[] a;
            delete[] top;
            delete[] next;
        }

};


int main(){

    NStacks ns(3, 6);
    cout<<ns.push(10, 1)<<endl;
    cout<<ns.push(20, 2)<<endl;
    cout<<ns.push(30, 3)<<endl;
    cout<<ns.push(40, 1)<<endl;
    cout<<ns.push(50, 2)<<endl;
    cout<<ns.push(60, 3)<<endl;
    cout<<ns.push(70, 1)<<endl;

    cout<<ns.pop(1)<<endl;
    cout<<ns.pop(2)<<endl;
    cout<<ns.pop(3)<<endl;
    cout<<ns.pop(1)<<endl;
    cout<<ns.pop(1)<<endl;
    return 0;
}