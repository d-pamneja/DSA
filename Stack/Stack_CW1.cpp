#include <iostream>
#include <stack>
using namespace std;

class Stack{
  public:
    int *arr;
    int size;
    int top;

  Stack(int size){
    arr = new int[size];
    this->size = size;
    this->top = -1;
  }

   void push(int data){
    if(top+1!=size){
      top++;
      arr[top] = data;
    }
    else{
      cout<<"Stack Overflow"<<endl;
      return;
    }
    
   }

   void pop(){
    if(top==-1){
      cout<<"Stack Underflow"<<endl;
      return;
    }
    else{
      top--;
    }
   }

   bool checkEmpty(){
    if(top==-1){
      return true;
    }
    return false;
   }

   int getSize(){
    return top+1;
   }

   int getTop(){
    if(top==-1){
      cout<<"Stack is empty : ";
      return -1;
    }
    else{
      int ans = arr[top];
      return ans;
    }
   }

   void printStack(Stack s){
    while(!s.checkEmpty()){
        cout<<s.getTop()<<" ";
        s.pop();
    }
    cout<<endl;
    }

};

void printStack(stack<int> s){// TC : O(n) SC : O(n)
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

void reverseString(string str){ // TC : O(n) SC : O(n)
    stack<char> s;

    for(int i=0;i<str.size();i++){
      s.push(str[i]);
    }

    while(!s.empty()){
      cout<<s.top();
      s.pop();
    }
}

int getMiddleFromStack(stack<int> s){ //TC : O(n) SC : O(n)
  int len = s.size();
  int mid = (len%2==0)? (len/2):(len/2)+1;

  while(mid!=1){
    s.pop();
    mid--;
  }
  return s.top();
}

void getMiddleFromStack(stack<int>&s,int &pos,int &ans){// TC : O(n) SC : O(n)
  if(s.empty()){
    return;
  }
  else{
    if(pos==1){
      ans = s.top();
    }

    pos--;
    int temp = s.top();
    s.pop();


    getMiddleFromStack(s,pos,ans);

    s.push(temp);
  }
}

void insertAtBottomOfStack(stack<int> &s,int data){ // TC : O(n) SC : O(n)
  if(s.empty()){
    s.push(data);
    return;
  }

  int temp = s.top();
  s.pop();
  insertAtBottomOfStack(s,data);

  s.push(temp);
}

void reverseStack(stack<int>&s){ // TC : O(n^2) SC : O(n)
  if(s.empty()){
    return;
  }

  int ele = s.top();
  s.pop();
  reverseStack(s);
  insertAtBottomOfStack(s,ele);
}

void insertInSortedStack(stack<int>&s,int &data){ // TC : O(n) SC : O(n)
    if(s.empty() || data > s.top()){ // SUPER IMPORTANT
        s.push(data);
        return;
    }

    int temp = s.top();
    s.pop();
    insertInSortedStack(s,data);
    s.push(temp);

}



int main(){
    Stack st(5);

    st.push(10);
    st.push(20);
    st.push(30);

    st.printStack(st);

    cout<<"Size of Stack: "<<st.getSize()<<endl;
    cout<<"Top element of Stack: "<<st.getTop()<<endl;
    cout<<"Stack Empty Status: "<<st.checkEmpty()<<endl;

    cout<<"-------------------------"<<endl;
    st.push(40);
    st.push(50);
    st.printStack(st);

    cout<<"Size of Stack: "<<st.getSize()<<endl;
    cout<<"Top element of Stack: "<<st.getTop()<<endl;
    cout<<"Stack Empty Status: "<<st.checkEmpty()<<endl;

    cout<<"-------------------------"<<endl;
    st.push(70);
    st.printStack(st);

    cout<<"Size of Stack: "<<st.getSize()<<endl;
    cout<<"Top element of Stack: "<<st.getTop()<<endl;
    cout<<"Stack Empty Status: "<<st.checkEmpty()<<endl;

    cout<<"-------------------------"<<endl;
    
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();

    st.printStack(st);

    cout<<"Size of Stack: "<<st.getSize()<<endl;
    cout<<"Top element of Stack: "<<st.getTop()<<endl;
    cout<<"Stack Empty Status: "<<st.checkEmpty()<<endl;

    cout<<"-------------------------"<<endl;


    string str = "dhruv";
    reverseString(str);

    cout<<"-------------------------"<<endl;


    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    cout<<getMiddleFromStack(s)<<endl;

    cout<<"-------------------------"<<endl;

    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    // s.push(60);

    cout<<"Stack : "<<endl;
    printStack(s);
    

    int len = s.size();
    int mid = (len%2==0)? (len/2):(len/2)+1;
    int pos = mid;

    int ans = -1;

    getMiddleFromStack(s,pos,ans);

    cout<<ans<<endl;

    cout<<"Stack : "<<endl;
    printStack(s);

    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    printStack(s);
    cout<<"--"<<endl;

    insertAtBottomOfStack(s,0);
        printStack(s);

        stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    printStack(s);
    cout<<"--"<<endl;

    int data = 0;

    insertInSortedStack(s,data);

    printStack(s);








    return 0;
}