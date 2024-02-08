#include <iostream>
#include <queue>
using namespace std;

// IMPORTANT: In Queue, Push happens from Back. While, Pop happens from Front

class Queue{ // Implement queue using Dynammic Array
  public:
    int *arr;
    int size;
    int front;
    int rear;

    Queue(int s){
      arr = new int[s];
      this->size = s;
      front = -1;
      rear = -1;
    }

    void push(int val){ // We use rear to push
      if(rear==size-1){
        cout<<"Queue Overflow"<<endl;
        return;
      }
      else if(front==-1 && rear==-1){ // Means empty queue (bhool jata hoon main ye condition)
          front++;
          rear++;
          arr[rear] = val;
          return;
        }
      else{ // Means not empty and not full
          rear++;
          arr[rear] = val;
          return;
        }
      }

      void pop(){ // We use front to pop
        if(rear==-1 && front==-1){ // Means empty queue
          cout<<"Queue underflow"<<endl;
          return;
        }
        else if(front==rear){ // Means single element (bhool jata hoon main ye condition)
          arr[front] = -1;
          rear = -1;
          front = -1;
        }
        else{ // Means not empty and more than 1 element
          arr[front] = -1;
          front++;
        }
      }

      bool isEmpty(){
        if(rear==-1 && front==-1){
          return true;
        }
        else{
          return false;
        }
      }

      int getSize(){
        if(front!=-1 && rear!=-1){ //(bhool jata hoon main ye condition)
          return rear-front+1 ;
        }
        else{
          return 0;
        }
      }

      int getFront(){
        if(front==-1){
          cout<<"Empty Queue"<<endl;
          return -1;
        }
        else{
          return arr[front];
        }
      }

      int getBack(){
        if(rear==-1){
          cout<<"Empty Queue"<<endl;
          return -1;
        }
        else{
          return arr[rear];
        }
      }

      void print(){
        cout<<"Printing Queue : ";
        for(int i=0;i<size;i++){
          cout<<arr[i]<<" ";
        }
        cout<<endl;
      }

      ~Queue(){
        delete arr;
      }

};

/* Now, upar wali queue has a disdvantage that it can't be used again after it's full.
// JAB front and rear pointer array ke Last index par honge
// To iss code ki help se hum kisi element ko insert nhi kar sete haz i.e. we CANNOT PUSH
// joki queue ki algorithm ke according array ki Oth index
// par insert hona chaive iska mtlb memory space waste he rha hai ›- Iska solution Circular Queue hai
*/

class CirQueue{ // Implement circular queue using Dynammic Array
  public:
    int *arr;
    int size;
    int front;
    int rear;

    CirQueue(int s){
      arr = new int[s];
      this->size = s;
      front = -1;
      rear = -1;
    }

    void push(int val){ // We use rear to push
      if((front==0 && rear==size-1)||rear==front-1 ){ // Queue Full (bhool jata hoon main ye condition)
        cout<<"Queue Overflow"<<endl;
        return;
      }
      else if(front==-1 && rear==-1){ // Means empty queue
          front++;
          rear++;
          arr[rear] = val;
          return;
        }
      else if(rear==size-1 && front!=0){ // Circular Case //(bhool jata hoon main ye condition)
        rear = 0;
        arr[rear] = val;
      }
      else{ // Normal Insert
          rear++;
          arr[rear] = val;
          return;
        }
    }

    void pop(){ // We use front to pop
      if(rear==-1 && front==-1){ // Means empty queue
        cout<<"Queue underflow"<<endl;
        return;
      }
      else if(front==rear){ // Means single element
        arr[front] = -1;
        rear = -1;
        front = -1;
      }
      else if(front == size-1){ // Circular Case //(bhool jata hoon main ye condition)
        arr[front] = -1;
        front = 0;
      }
      else{ // Means not empty and more than 1 element
        arr[front] = -1;
        front++;
      }
    }

    bool isEmpty(){
      if(rear==-1 && front==-1){
        return true;
      }
      else{
        return false;
      }
    }

    int getSize(){
      if(front!=-1 && rear!=-1){
        return rear-front+1 ;
      }
      else{
        return 0;
      }
    }

    int getFront(){
      if(front==-1){
        cout<<"Empty Queue"<<endl;
        return -1;
      }
      else{
        return arr[front];
      }
    }

    int getBack(){
      if(rear==-1){
        cout<<"Empty Queue"<<endl;
        return -1;
      }
      else{
        return arr[rear];
      }
    }

    void print(){
        cout<<"Printing Queue : ";
        for(int i=0;i<size;i++){
          cout<<arr[i]<<" ";
        }
        cout<<endl;
      }

    ~CirQueue(){
      delete arr;
    }

};

class DeQue{ // Implement Circular DE queue using Array
  public:
    int *arr;
    int size;
    int front;
    int rear;

    DeQue(int s){
      arr = new int[s];
      this->size = s;
      front = -1;
      rear = -1;
    }

    void pushFront(int val){
      if((front==0 && rear==size-1)||rear==front-1){ // Queue Full (bhool jata hoon main ye condition)
        cout<<"Queue Overflow"<<endl;
        return;
      }
      else if(front==-1 && rear==-1){ // Empty Deque
        front++;
        rear++;
        arr[front] = val; 
      }
      else if(front==0 && rear!=size-1){ // Circular Case (bhool jata hoon main ye condition)
        front = size - 1;
        arr[front] = val;
      }
      else{ // Normal Case
        front--;
        arr[front] = val;
      }
    }

    void pushBack(int val){
      if((front==0 && rear==size-1)||rear==front-1){ // Queue Full
        cout<<"Queue Overflow"<<endl;
        return;
      }
      else if(front==-1 && rear==-1){ // Means empty queue
          front++;
          rear++;
          arr[rear] = val;
          return;
        }
      else if(rear==size-1 && front!=0){ // Circular Case
        rear = 0;
        arr[rear] = val;
      }
      else{ // Normal Insert
          rear++;
          arr[rear] = val;
          return;
      }
    }

    void popFront(){
      if(rear==-1 && front==-1){ // Means empty queue
        cout<<"Queue underflow"<<endl;
        return;
      }
      else if(front==rear){ // Means single element
        arr[front] = -1;
        rear = -1;
        front = -1;
      }
      else if(front == size-1){ // Circular Case
        arr[front] = -1;
        front = 0;
      }
      else{ // Means not empty and more than 1 element
        arr[front] = -1;
        front++;
      }
    }

    void popBack(){
      if(rear==-1 && front==-1){ // Means empty queue
        cout<<"Queue underflow"<<endl;
        return;
      }
      else if(front==rear){ // Means single element
        arr[front] = -1;
        rear = -1;
        front = -1;
      }
      else if(rear==0){ // Circular Case (bhool jata hoon main ye condition)
        arr[rear] = -1;
        rear = size-1;
      }
      else{ // Means not empty and more than 1 element
        arr[rear] = -1;
        rear--;
      }

    }


    ~DeQue(){
      delete arr;
    }
  
};

void printQueue(queue<int> qu){
    while(!qu.empty()){
      cout<<qu.front()<<endl;
      qu.pop();
    }
}



int main() {
  // queue<int> qu;
  // qu.push(1);
  // qu.push(2);
  // qu.push(3);
  // qu.push(4);
  // qu.push(5);

  // printQueue(qu);
  // cout<<"Size of Queue: "<<qu.size()<<endl;

  // if(qu.empty()) cout<<"Queue is empty!"<<endl;
  // else cout<<"Not empty."<<endl;

  // qu.pop();
  // cout<<"---"<<endl;
  // printQueue(qu);
  // cout<<"Size of Queue: "<<qu.size()<<endl;

  // if(qu.empty()) cout<<"Queue is empty!"<<endl;
  // else cout<<"Not empty."<<endl;

//   Queue qu(5);
//   qu.print();

//   qu.push(10);
//   qu.print();

//   qu.push(20);
//   qu.print();

//   qu.push(30);
//   qu.print();

//   qu.push(40);
//   qu.print();

//   qu.push(50);
//   qu.print();

//   qu.push(60);
//   qu.print();

//   qu.pop();
//   qu.print();

//   qu.pop();
//   qu.print();

//   qu.pop();
//   qu.print();

//   qu.pop();
//   qu.print();

//   qu.pop();
//   qu.print();

//   qu.pop();
//   qu.print();

//   int front = -1;
//   int back = -1;

//   qu.push(10);
//   qu.print();

//   cout<<"Front : "<<qu.getFront()<<endl;

//   qu.push(20);
//   qu.print();
//   cout<<"Back : "<<qu.getBack()<<endl;

//   qu.pop();
//   qu.pop();

//   cout<<"Size : "<<qu.getSize();
    
    CirQueue q(5);
    q.print();

    q.push(10);
    q.print();

    q.push(20);
    q.print();

    q.push(30);
    q.print();

    q.push(40);
    q.print();
    
    q.push(50);
    q.print();

    q.push(60);
    q.print();

    q.pop();
    q.pop();
    q.pop();
    q.print();

    q.push(100);
    q.print();

    q.push(110);
    q.print();

    q.push(120);
    q.print();

    q.push(130);
    q.print();
    return 0;
}