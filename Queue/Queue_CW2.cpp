#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// Q1. Reverse a queue using stack
void reverseQueue(queue<int> &q){ // Using Stack //TC: O(n) SC:O(n) Same Effective Space
  stack<int> st;

  while(!q.empty()){ // Remove from queue and push in stack
    int front = q.front();
    q.pop();

    st.push(front);
  }

  while(!st.empty()){ // Remove from stack and push in queue
    int top = st.top();
    st.pop();

    q.push(top);
  }
}

void reverseQueueRecursion(queue<int> &q){ // TC: O(n) SC: O(n)
  if(q.empty()){ // Base Case
    return;
  }

  int temp = q.front(); // Processing
  q.pop();

  reverseQueueRecursion(q); // Recrusive Call

  q.push(temp);
}

// Q2. Reverse first K elements of a queue
void reverseFirstKQueue(queue<int> &q,int k){ // TC: O(n) SC: O(n)
  if(k==0 || k>q.size()){
    return;
  }

  int rev = k;
  int leftrev = q.size() - k;

  stack<int> st;

  while(rev){ // Push all k elements in stack
    int front = q.front();
    q.pop();

    st.push(front);
    rev--;
  }

  while(!st.empty()){ // Push all elements of stack back into queue
    int top = st.top();
    st.pop();

    q.push(top);
  }

  while(leftrev){ // push and pop first (n-k) elements into queue again
    int front = q.front();
    q.pop();

    q.push(front);

    leftrev--;
  }
}

// Q3. Interleave first and second half of a queue
void interleaveQueue(queue<int> &first){
  queue<int> second;
  int size = first.size();

  for(int i=0;i<size/2;i++){ // POP from first and PUSH first half in second queue
    int temp = first.front();
    first.pop();

    second.push(temp);
  }

  // MERGE BOTH THE HALVES: POP and PUSH elements alternatively in first queue to get answer
  for(int i=0;i<size/2;i++){ 
    int temp = second.front();
    second.pop();
    first.push(temp);

    temp = first.front();
    first.pop();
    first.push(temp);
  }

  if(size&1==1){
    int front = first.front();
    first.pop();

    first.push(front);
  }
}

// Q4. Find first negative integer in every window of size k
void firstNegativeinKWindow(int *arr, int n,int k){
  // SLIDING WINDOW APPROACH
  queue<int> q;

  // Initialise the first window with kth element
  for(int i=0;i<k;i++){
    int element = arr[i];
    if(element<0){
      q.push(i); // Push the index of -ve numbers in first window in queue
    }
  }

  // Process remaining windows using - 1. Removal and 2. Addition
  for(int i=k;i<n;i++){
    // Before moving ahead, fetch the answer of previous window
    if(q.empty()){
      cout<<"0"<<" ";
    }
    else{
      cout<<arr[q.front()]<<" ";
    }

    //Removal - Jo bhi index out of range hai, usse remove kar do
    if(i-q.front()>=k){ // This condition means range se agge nikal gaya ith index from last -ve term
      q.pop();
    }

    // Addition
    if(arr[i]<0){ // Means new negative element mila toh add kar do
      q.push(i);
    }
  }

  // Last Window ka answer alga se print kar do
  if(q.empty()){
    cout<<"0"<<" ";
  }
  else{
    cout<<arr[q.front()]<<" ";
  }
}





void printQueue(queue<int> qu){
    cout<<"Printing Queue : ";
    while(!qu.empty()){
      cout<<qu.front()<<" ";
      qu.pop();
    }
    cout<<endl;
}

int main() {
  queue<int> q;
  q.push(10);
  q.push(20);
  q.push(30);
  q.push(40);
  q.push(50);
  q.push(60);
  q.push(70);
  q.push(80);
  q.push(90);
  printQueue(q);

  reverseQueue(q);
  printQueue(q);


  reverseQueueRecursion(q);
  printQueue(q);

  int k = 3;
  reverseFirstKQueue(q,k);
  printQueue(q);

  interleaveQueue(q);
  printQueue(q);

  cout<<"------------------------------------"<<endl;

  int arr[] = {2,-5,4,-1,-2,0,5};
  int n1 = 7;
  int k1 = 3;
  firstNegativeinKWindow(arr,n1,k1);

  return 0;
}