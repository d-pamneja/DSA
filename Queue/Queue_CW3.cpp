#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// Q1. First Non Repeating/Unique Character in a String (Leetcode-387)
int firstUniqChar(string s) { // TC: O(n) SC: O(n)
    unordered_map<char, int> charCount;
    queue<char> q;
    int ans = -1;

    for (int i=0;i<s.size();i++) {
        charCount[s[i]]++;
        q.push(s[i]);

    }

    int i = 0;
    while(!q.empty()){
        if(charCount[q.front()]>1){ // Means not the answer
            q.pop();
            i++;
        }
        else{ // Means this is the answer i.e. this cannot be = 0, only >1 or =1
            ans = i;
            break;
        }
    }

    return ans;

}

// Q2. Gas Station (Leetcode-134) - V.V.V.V.Imp
/*
Yaha par ek badia approach hai jisko YAAD RAKHNA HAI acche se
which is ek while traversing each station, jaha par bhi gas khatam ho jata hai i.e. jaha parr failure ho jata hai
humme ussi failure station ke baad wale station se start karna hai
WE DO NOT NEED TO CHECK EACH STATION AGAIN AND AGAIN. 
Common sense ki baat hai ki agar kisi station se start karke hum kisi station tak pahuch nahi pa rahe hai toh
uske baad (yaani that starting station) wale stations se start karke bhi hum waha tak nahi pahuchenge. 
We will have to start from the next station of the failure station.

So, we will use a queue to store the failure stations and then we will start from the next station of the failure station. 
THAT IS WHY WE ARE USING QUEUE
*/ 

// Greedy Approach - TC: O(n) SC: O(1)
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    // GREEDY APPROACH
    int deficit = 0;
    int balance = 0;

    // Index from where we are starting from, start from any complexity will be same
    int start = 0;

    // Har index ko check karna hai, ki voh answer hai ya nahi
    for(int i = 0;i<gas.size();i++){
        balance = balance + gas[i] - cost[i];

        if(balance<0){
            deficit += abs(balance);
            start = i+1;
            balance = 0;
        }
    }

    if(balance-deficit>=0){
        return start;
    }
    else{
        return -1;
    }
        
    

    // // Queue Approach - TC: O(n) SC: O(n)
    // int n = gas.size();
    // queue<int> q;
    // int start = 0;
    // int sum = 0;

    // for (int i=0;i<n;i++) {
    //     sum += gas[i] - cost[i];
    //     if (sum < 0) {
    //         q.push(i);
    //         start = i+1;
    //         sum = 0;
    //     }
    // }

    // if (start == n) {
    //     return -1;
    // }

    // while(!q.empty()) {
    //     sum += gas[start] - cost[start];
    //     if (sum < 0) {
    //         q.pop();
    //         start = start+1;
    //         sum = 0;
    //     }
    //     else {
    //         q.push(start);
    //         start = start+1;
    //     }
    // }

    // return start;
}

// Q3. Sliding Window Maximum (Leetcode-239) - V.V.V.V.Imp
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    deque<int> dq;

    // First Window Creation
    for(int i=0;i<k;i++){
        int ele = nums[i];

        // Jitne bhi queue ke andar iss element se chotte hai remvove kardo
        while(!dq.empty() && ele > nums[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);

    }

    // Remaining Window ko Process karo
    for(int i=k;i<nums.size();i++){
        // Store the answer
        ans.push_back(nums[dq.front()]);

        // Removal
            // Out of index walle 
        if(!dq.empty() && i-dq.front()>=k){
            dq.pop_front();
        }

            // Chotte elements ko pop kardo
        int ele = nums[i];

        // Jitne bhi queue ke andar iss element se chotte hai remvove kardo
        while(!dq.empty() && ele > nums[dq.back()]){
            dq.pop_back();
        }

        // Addition
        dq.push_back(i);
    }

    // Last Window ka answer store karo
    ans.push_back(nums[dq.front()]); // Queue will never be empty here as we are always storing maximum
    
    return ans;
}


int main(){


    return 0;
}