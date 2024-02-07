#include <iostream>
#include <stack>
using namespace std;

//Q1. Implement an array using two stacks - IMP
class Stack{ // TC : O(1) SC : O(n)
  public:
    int *arr;
    int size;
    int top1;
    int top2;

  Stack(int size){
    arr = new int[size];
    this->size = size;
    this->top1 = -1;
    this->top2 = size;
  }

   void push1(int data){
    if(top2-top1!=1){
      top1++;
      arr[top1] = data;
    }
    else{
      cout<<"Stack 1 Overflow"<<endl;
      return;
    }
   }

   void push2(int data){
    if(top2-top1!=1){
      top2--;
      arr[top2] = data;
    }
    else{
      cout<<"Stack 2 Overflow"<<endl;
      return;
    }
   }

   void pop1(){
    if(top1==-1){
      cout<<"Stack 1 Underflow"<<endl;
      return;
    }
    else{
      arr[top1]=-1;
      top1--;
    }
   }

   void pop2(){
    if(top2==size){
      cout<<"Stack 2 Underflow"<<endl;
      return;
    }
    else{
      arr[top2]=-1;
      top2++;
    }
   }

  //  bool checkEmpty(){
  //   if(top==-1){
  //     return true;
  //   }
  //   return false;
  //  }

   int getSize1(){
    return top1+1;
   }

   int getSize2(){
    return size - top2;
   }

   int getTop1(){
    if(top1==-1){
      cout<<"Stack 1 is empty : ";
      return -1;
    }
    else{
      int ans = arr[top1];
      return ans;
    }
   }

   int getTop2(){
    if(top2==size){
      cout<<"Stack 2 is empty : ";
      return -1;
    }
    else{
      int ans = arr[top2];
      return ans;
    }
   }

   void print(){
    cout<<"Top 1 : "<<top1<<endl;
    cout<<"Top 2 : "<<top2<<endl;
    for(int i=0;i<size;i++){
      cout<<arr[i]<<" ";
    }
   }

};


// Q2. Valid Parenthesis - (Leetcode 20) - V.V.IMP
 bool isValid(string s) { // TC : O(n) SC : O(n)
    stack<char> st;

    for(int i=0;i<s.size();i++){
        if(s[i]=='(' || s[i]=='{' ||s[i]=='[' ){
            st.push(s[i]);
        }
        else{
            if(!st.empty()){
                if(s[i]==')' && st.top()=='('){
                    st.pop();
                }
                else if(s[i]=='}' && st.top()=='{'){
                    st.pop();
                }
                else if(s[i]==']' && st.top()=='['){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }  
        }
    }

    if(st.size()==0){
        return true;
    }
    else{
        return false;
    }
    
}

// Q3. Remove Redundant Brackets
bool RedundantBrackets(string &s){ // TC : O(n) SC : O(n)
  stack<char> st;

  for(int i=0;i<s.size();i++){
    if(s[i]=='(' || s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='%'){
      st.push(s[i]);
    }
    else if(s[i]==')'){
      int opcount = 0;

      while(!st.empty() && st.top()!='('){
        char temp = st.top();
        if(temp=='+' || temp=='-' || temp=='*' || temp=='/' || temp=='%' ){
          opcount++;
        }
        st.pop();
      }

      st.pop();

      if(opcount==0){
        return true;
      }

    }
  }
  return false;
  
}

// Q4. Min Stack - (Leetcode 155) - V.V.V.IMP
class MinStack { // TC : O(1) SC : O(n)
public:
    vector<pair<int,int >> st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            pair<int,int > p;
            p.first = val;
            p.second = val;
            st.push_back(p);
        }
        else{
            pair<int,int > p;
            p.first = val;
            int oldMin = st.back().second;
            p.second = min(oldMin,val);
            st.push_back(p);
        }
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        pair<int,int> rightMost = st.back();
        return rightMost.first;
    }
    
    int getMin() {
        pair<int,int> rightMost = st.back();
        return rightMost.second;
    }
};

// Q5. Next Smaller Element - (GFG) - V.V.IMP
vector<int> nextSmallerElement(int *arr, int size,vector<int> &ans){ // TC : O(n) SC : O(n)
  stack<int> st;
  st.push(-1);

  for(int i=size-1;i>=0;i--){
    int num = arr[i];

    while(st.top()>=num){
      st.pop();
    }
    ans[i] = st.top();
    st.push(num);
  }
  return ans;
}

// Q6. Previous Smaller Element - V.V.IMP
vector<int> prevSmallerElement(int *arr, int size,vector<int> &ans){ // TC : O(n) SC : O(n)
  stack<int> st;
  st.push(-1);

  for(int i=0;i<size;i++){
    int num = arr[i];

    while(st.top()>=num){
      st.pop();
    }
    ans[i] = st.top();
    st.push(num);
  }
  return ans;
}


// Q7. Next Larger Element - (GFG) - V.V.IMP
vector<long long> nextLargerElement(vector<long long> arr, int n){
    stack<int> st;
    
    vector<long long> ans(n,-1);
    
    for(int i=0;i<n;++i){
        while(!st.empty() && arr[i] > arr[st.top()]){
            ans[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
    
}

// Q8. Largest Area Histogram - (Leetcode 84) - V.V.V.V.IMP
vector<int> nextSmallerElementHist(vector<int> arr){ // TC : O(n) SC : O(n)
    stack<int> st;
    st.push(-1);

    vector<int> ans(arr.size());

    for(int i=arr.size()-1;i>=0;i--){
        int num = arr[i];

        while(st.top()!=-1 && arr[st.top()]>=num){
        st.pop();
        }
        ans[i] = st.top();
        if(ans[i]==-1){
            ans[i]=arr.size();
        }
        st.push(i);
    }
    return ans;
}

vector<int> prevSmallerElementHist(vector<int> arr){ // TC : O(n) SC : O(n)
    stack<int> st;
    st.push(-1);

    vector<int> ans(arr.size());

    for(int i=0;i<arr.size();i++){
        int num = arr[i];

        while(st.top()!=-1 && arr[st.top()]>=num){
        st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int>& heights) {

    vector<int> next = nextSmallerElementHist(heights);
    vector<int> prev = prevSmallerElementHist(heights);

    vector<int> area(next.size());

    for(int i=0;i<area.size();i++){
        int width = next[i] - prev[i] - 1;
        int length = heights[i];

        int currArea = width*length;

        area[i] = currArea;
    }

    int MAXI = INT_MIN;

    for(auto i:area){
        MAXI = max(i,MAXI);
    }

    return MAXI;
}


int main(){

    Stack st(6);

    st.print();
    cout<<endl;
    cout<<"--"<<endl;
    
    st.push1(10);
    st.print();

    cout<<endl;
    cout<<"--"<<endl;
    
    st.push1(20);
    st.print();

    cout<<endl;
    cout<<"--"<<endl;

    st.push1(30);
    st.print();

    cout<<endl;
    cout<<"--"<<endl;
    
    st.push2(60);
    st.print();

    cout<<endl;
    cout<<"--"<<endl;
        
    st.push2(50);
    st.print();

    cout<<endl;
    cout<<"--"<<endl;
    
    st.push2(40);
    st.print();

    cout<<endl;
    cout<<"--"<<endl;
    
    st.pop1();
    st.print();

    cout<<endl;
    cout<<"--"<<endl;

    st.pop2();
    st.print();

    cout<<endl;
    cout<<"--"<<endl;

    st.pop2();
    st.print();

    cout<<endl;
    cout<<"--"<<endl;

    st.pop2();
    st.print();

    cout<<endl;
    cout<<"--"<<endl;

    st.pop2();
    st.print();

    cout<<endl;
    cout<<"--"<<endl;

    st.pop1();
    st.print();

    cout<<endl;
    cout<<"--"<<endl;

    st.pop1();
    st.print();

    cout<<endl;
    cout<<"--"<<endl;

    st.pop1();
    st.print();

    cout<<endl;
    cout<<"--"<<endl;

    int arr[5] = {8,4,6,2,3};
    int size = 5;

    vector<int> ans(5);
    nextSmallerElement(arr,5,ans);

    for(auto i:ans){
        cout<<i<<",";
    }
    cout<<endl;

    cout<<"--"<<endl;
    int arr[5] = {8,4,6,2,3};
    int size = 5;

    vector<int> ans(size);

    prevSmallerElement(arr,size,ans);

    for(auto i:ans){
      cout<<i<<",";
    }
    cout<<endl;




  

  
  return 0;
}