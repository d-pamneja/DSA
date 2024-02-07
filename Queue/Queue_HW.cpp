#include <iostream>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

// Q1. Implement Queue using Stack - (Leetcode-232) V.IMP 
class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;

    // We will implement the method where push happens in O(1) while front and pop happend in O(n)
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if(!st2.empty()){
            int front = st2.top();
            st2.pop();
            return front;
        }
        else{
            while(!st1.empty()){
                int temp = st1.top();
                st1.pop();
                st2.push(temp);
            }

            int front = st2.top();
            st2.pop();
            return front;

        }
        
    }
    
    int peek() {
        if(!st2.empty()){
            int front = st2.top();
            return front;
        }
        else{
            while(!st1.empty()){
                int temp = st1.top();
                st1.pop();
                st2.push(temp);
            }

            int front = st2.top();
            return front;

        }
    }
    
    bool empty() {
        return (st1.empty() && st2.empty());
        
    }
};

// Q2. Implement Stack using Queue - (Leetcode 225) -V.IMP
class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);

        for(int i=0;i<q.size()-1;++i){
            int front = q.front();
            q.pop();
            q.push(front);
        }
    }
    
    int pop() {
        int top = q.front();
        q.pop();
        return top;
        
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

// Q3. Sum of min/max element of all subarray of size "k"
vector<int> sumofminmaxofallwindowofsizek(vector<int>& nums, int k,int &sol) {
    vector<int> ans;
    deque<int> dq1;
    deque<int> dq2;

    // First Window Creation
    for(int i=0;i<k;i++){
        int ele = nums[i];

        // Jitne bhi queue ke andar iss element se chotte hai remvove kardo
        while(!dq1.empty() && ele >= nums[dq1.back()]){
            dq1.pop_back();
        }
        dq1.push_back(i);

        // Jitne bhi queue ke andar iss element se badde hai remvove kardo
        while(!dq2.empty() && ele <= nums[dq2.back()]){
            dq2.pop_back();
        }
        dq2.push_back(i);

    }

    // Remaining Window ko Process karo
    for(int i=k;i<nums.size();i++){
        // Store the answer
        ans.push_back(nums[dq1.front()]+nums[dq2.front()]);

        // Removal
            // Out of index walle 
        if(!dq1.empty() && i-dq1.front()>=k){
            dq1.pop_front();
        }

        if(!dq2.empty() && i-dq2.front()>=k){
            dq2.pop_front();
        }

            // Chotte elements ko pop kardo
        int ele = nums[i];

        // Jitne bhi queue ke andar iss element se chotte hai remvove kardo
        while(!dq1.empty() && ele >= nums[dq1.back()]){
            dq1.pop_back();
        }

        while(!dq2.empty() && ele <= nums[dq2.back()]){
            dq2.pop_back();
        }

        // Addition
        dq1.push_back(i);
        dq2.push_back(i);
    }

    // Last Window ka answer store karo
    ans.push_back(nums[dq1.front()]+nums[dq2.front()]); // Queue will never be empty here as we are always storing maximum - minimum

    for(auto el:ans){
      sol+=el;
    }
    
    return ans;
}


// Q4. Recent Calls (Leetcode-933)
class RecentCounter {
public:
    queue<int> q;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        //1. Push current element in Queue
        q.push(t);

        while(!q.empty() && t-3000>q.front()){ // This will effectively remove all elements less than t - 3000
            q.pop();
        }

        return q.size(); // In the end, queue will have all elements within the desired range
    }
};

// Q5. Find the Winner of the Circular Game (Leetcode-1823)
int findTheWinner(int n, int k) {
    queue<int> q;
    for(int i=1;i<n+1;i++){ // Make all players enter the queue
        q.push(i);
    }

    int i = 1;
    while(q.size()>1){
        // int temp = q.front();
        // q.pop();

        // if(i!=k){
        //     q.push(temp);
        //     i++;
        // }
        // else{
        //     i = 1;
        // }

        for(int i=1;i<k;i++){
            int player = q.front();

            q.pop();

            q.push(player);
        }

        q.pop();
    }
    return q.front();
}

int main(){
    return 0;
}