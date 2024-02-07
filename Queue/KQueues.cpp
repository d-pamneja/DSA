#include <iostream>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

class KQueues{
    public:
        int *arr;
        int *front;
        int *rear;
        int *next;
        int n, k;
        int freespot;

        KQueues(int _k, int _n){
            this->k = _k;
            this->n = _n;
            arr = new int[n];
            freespot = 0; // Indicates the next free spot in the array
            next = new int[n];  // next[i] indicates the next free spot in the array
            front = new int[k]; // front[i] indicates the front of the ith queue
            rear = new int[k]; // rear[i] indicates the rear of the ith queue

            for(int i=0;i<k;i++)
                front[i] = rear[i] = -1;
            
            for(int i=0;i<n-1;i++)
                next[i] = i+1;

            next[n-1] = -1; // Indicates end of the array
        }

        bool push(int x, int qi){
            // Overflow
            if(freespot == -1){
                cout<<"Queue Overflow"<<endl;
                return false;
            }

            // Find the next free spot
            int index = freespot;

            // Update the next free spot
            freespot = next[index];

            // Check if this is the first element in the queue i
            if(front[qi]==-1){
                front[qi]= index;
            }
            else{
                // Link that element to that Queue's rearest element
                next[rear[qi]] = index; // IMP
            }

            // Update next
            next[index] = -1;

            // Update rear
            rear[qi] = index;

            // Update the array
            arr[index] = x;
            return true;
        }  

        int pop(int qi){ 
            // Underflow
            if(front[qi] == -1){
                cout<<"Queue Underflow"<<endl;
                return -1;
            }

            // Find the index to pop
            int index = front[qi];

            // Update front
            front[qi] = next[index];

            // Update next
            next[index] = freespot;

            // Update freespot
            freespot = index;

            // Return the element
            return arr[index];
        }

        ~KQueues(){
            delete[] arr;
            delete[] front;
            delete[] rear;
            delete[] next;
        } 
};


int main(){
    KQueues kq(3, 8);
    cout<<kq.push(15, 2)<<endl;
    cout<<kq.push(45, 2)<<endl;
    cout<<kq.push(17, 1)<<endl;
    cout<<kq.push(49, 1)<<endl;
    cout<<kq.push(39, 1)<<endl;

    cout<<kq.pop(2)<<endl;
    cout<<kq.pop(1)<<endl;

    return 0;
}