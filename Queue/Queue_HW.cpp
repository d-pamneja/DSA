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

// Q6. Reveal Cards In Increasing Order (Leetcode-950)
vector<int> deckRevealedIncreasing(vector<int>& deck) {
    sort(deck.begin(),deck.end());
    vector<int> ans(deck.size());
    queue<int> q;

    for(int i=0;i<ans.size();i++) // Put all indices of ans in queue
        q.push(i);
    
    for(int i=0;i<ans.size();i++){ // Reverse Simulation + Fill the answer
        // Reveal step
        ans[q.front()] = deck[i];
        q.pop();

        // Push front to bottom
        if(!q.empty()){
            q.push(q.front());
            q.pop();
        }

        // sort -> {2,3,5,7,11,13,17}

        // queue -> {0,1,2,3,4,5,6}

        // ans -> {0,0,0,0,0,0,0}
    }

    return ans;
}

// Q7. Number of People Aware of a Secret (Leetcode-1953) - V.V.Imp
int peopleAwareOfSecret(int n, int delay, int forget) {
    const int M = 1e9 + 7;


    int curr = 0; // Active Spreader
    int ans = 1; // No. of people who know the secret

    queue<pair<int,int>> delayQ,forgetQ; // <uss din, kitne logo ko secret pata laga>
    
    delayQ.push({1,1});
    forgetQ.push({1,1});

    for(int i=1;i<=n;++i){
            // Step1. Active spreaders and person who know ko kaam karo
            if(!forgetQ.empty() && forgetQ.front().first + forget <= i){ // Matlab kya jis din usse pata chala secret, kya uss din ko 'forget' days ho gaye hai i.e. yeh log bholne walle hai 
            auto front = forgetQ.front();
            forgetQ.pop();

            auto num = front.second; // Means number of people jinko aaj bholne walla hai secret
            ans = (ans - num + M)%M;
            curr = (curr - num + M)%M;
            }

            // Step2. Make new active spreaders
            if(!delayQ.empty() && delayQ.front().first + delay <= i){ // Matlab kya jis din usse pata chala secret, kya uss din ko 'delay' days ho gaye hai i.e. yeh log secret spread karna shuru karne walle hai matlab active hone walle hai
            auto front = delayQ.front();
            delayQ.pop();

            auto num = front.second; // Means number of people jinko aaj active honne walle hai
            curr = (curr + num)%M; // Means jitne logo ko abh secret pata chal jayega, as active person will tell one person each
            }

            // Step3. Spread the secret
            if(curr>0){
                ans = (ans + curr)%M;
                delayQ.push({i,curr}); // Cause yehi log kuch din mein active honne walle hai
                forgetQ.push({i,curr}); // Cause jo log current hai abhi utne hi aaj add hue hongay
            }
    }

    return ans;
    
}

// Q8. Rotten Oranges (Leetcode-994) - V.V.V.V.Imp
int orangesRotting(vector<vector<int>>& grid) {
    // Queue approach
    int time = -1;
    int noOfRottenOrg = 0;
    int noOfFreshOrg = 0;

    queue<pair<int,int>> q; // To store the index's of rotten oranges, both present and future

    int n = grid.size();
    int m = grid[0].size();

    for(int i=0;i<n;i++){ // Traverse the grid once to fetch no of fresh and rotten oranges
        for(int j=0;j<m;j++){
            // Case 1. If the orange is rotten
            if(grid[i][j]==2){
                q.push({i,j}); // Push the index of the rotten orange
                grid[i][j] == -1; // Elemenating the value
                noOfRottenOrg++;
            }

            // Case 2. If the orange is fresh
            if(grid[i][j]==1){
                noOfFreshOrg++;
            }
        }
    }

    // Base checks before proceeding
    if(noOfFreshOrg==0) return 0; // Means immediately all are rotten as no fresh oranges exist
    else if(noOfFreshOrg!=0 && noOfRottenOrg==0) return -1; // Means since no rotten oranges exist at intitial stage, answer is not possible
    else if(noOfFreshOrg==0 && noOfRottenOrg!=0) return 0; // Means all are rotten so no time needed

    int futureRottenOrg = 0;

    while(!q.empty()){
        time++;

        int size = q.size();

        for(int k=0;k<size;k++){ // We use this loop to make all adjacent oranges rotten of a given rotten orange
            
            int i = q.front().first;
            int j = q.front().second;

            // Upwards
            if((i-1)>=0 && grid[i-1][j]==1){ // Means if a fresh orange exists upwards
                q.push({i-1,j}); // Push this orange to the queue as it becomes rotten as in future, it will rot further oranges
                grid[i-1][j] = -1; // Elemenate the value
                futureRottenOrg++;
            }

            // Downwards
            if((i+1)<n && grid[i+1][j]==1){ // Means if a fresh orange exists downwards
                q.push({i+1,j}); // Push this orange to the queue as it becomes rotten as in future, it will rot further oranges
                grid[i+1][j] = -1; // Elemenate the value
                futureRottenOrg++;
            }

            // Rightwards
            if((j+1)<m && grid[i][j+1]==1){ // Means if a fresh orange exists rightwards
                q.push({i,j+1}); // Push this orange to the queue as it becomes rotten as in future, it will rot further oranges
                grid[i][j+1] = -1; // Elemenate the value
                futureRottenOrg++;
            }

            // Leftwards
            if((j-1)>=0 && grid[i][j-1]==1){ // Means if a fresh orange exists leftwards
                q.push({i,j-1}); // Push this orange to the queue as it becomes rotten as in future, it will rot further oranges
                grid[i][j-1] = -1; // Elemenate the value
                futureRottenOrg++;
            }

            // Finally, we pop the orange for which we were getting the answer
            q.pop();
        }

    }

    if(futureRottenOrg!=noOfFreshOrg) return -1;
    else return time;
}

// Q9. Overlapping Intervals (Leetcode-56) - V.V.Imp
static bool myComp(const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0];
};

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if(intervals.empty()){
        return vector<vector<int>>();
    }
    
    sort(intervals.begin(),intervals.end(),myComp);
    
    stack<vector<int>>st;
    
    st.push(intervals[0]); // Push first element
    
    for(int i=1;i<intervals.size();i++){
        vector<int> element = intervals[i];
        vector<int> &top = st.top();
        
        if(element[0] <= top[1]){ // If the starting of element collides with the end of previous inetrval, we merge these two
            top[1] = max(top[1],element[1]); // Make the end of item at top as the maximum of the two end times
        }
        else{
            st.push(element);
        }
    }
    
    // Convert the stack to a vector - Nice method, dekh lena ek baar
    vector<vector<int>> mergedIntervals;
    while (!st.empty()) {
        mergedIntervals.insert(mergedIntervals.begin(), st.top());
        st.pop();
    }
    
    return mergedIntervals;
}



int main(){
    return 0;
}