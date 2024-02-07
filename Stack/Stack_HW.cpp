#include <iostream>
#include <stack>
#include<string.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Q1. Minimum Bracket Reversal/Count the Reversal - (GFG)
int countRev (string s){ // TC : O(n) SC : O(n)
    // your code here
    if(s.size() & 1){
        return -1;
    }
    
    int ans = 0;
    
    stack<char> st;
    
    for(auto ch:s){
        if(!st.empty() && ch=='{'){
            st.push(ch);
        }
        else{
            if(!st.empty() && st.top()=='{'){ // means we found a pair, so we cancel them out
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
    }
    
    // Now, check the stack for actual count of pairs
    while(!st.empty()){ // Means unbalanced left
        char ch1 = st.top();
        st.pop();
        
        char ch2 = st.top();
        st.pop();
        
        if(ch1==ch2){
            ans += 1;
        }
        else{
            ans+=2;
        }
    }
    
    return ans;
    
}

// Q2. Remove All Adjacent Duplicates In String - (Leetcode 1047)
string removeDuplicates(string s) { //TC : O(n) SC : O(n)
    stack<char> st;

    for(auto ch:s){
        if(!st.empty() && ch==st.top()){
            st.pop();
        }
        else{
            st.push(ch);
        }
    }

    string ans = "";

    while(!st.empty()){
        ans = st.top() + ans;
        st.pop();
    }

    return ans;
}

// Q3. Celebrity Problem - (GFG) - V.V IMP
int celebrity(vector<vector<int> >& M, int n) { // TC : O(n) SC : O(n)
    stack<int> st;
    
    for(int i=0;i<n;i++){ //step 1: push all persons into stack
        st.push(i);
    }
    
    //step 2: run discard method, to get a potential Celebrity
    while(st.size()!=1){
        int a = st.top();
        st.pop();
        
        int b = st.top();
        st.pop();
        
        if(M[a][b]){ //if a knows b?
            st.push(b); // a lis not celebrity, b might be
        }
        else{
            st.push(a); // b is not celebrity, a might be
        }
    }
    
    //step 3: Check that single person is actually celebrity?
    int celeb = st.top();
    st.pop();
    
    for(int i=0;i<n;i++){ // Cel. should not know anyone
        if(M[celeb][i]!=0){
            return -1;
        }
    }
    
    for(int i=0;i<n;i++){ // Cel. should not be known by anyone
        if(M[i][celeb]==0 && i!=celeb){
            return -1;
        }
    }


    return celeb;
    
    
}

// Q4. Online Stock Span - (Leetcode 901)
class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;
        while(!st.empty() && st.top().first<=price){
            span += st.top().second;
            st.pop();
        }
        st.push({price,span});

        return span;
    }
};

// Q5. Check If Word Is Valid After Substitutions - (Leetcode 1003)
bool isValid(string s) {
    if(s[0]!='a') return false;

    stack<char> st;

    for(auto ch:s){
        if(ch=='a'){
            st.push(ch);
        }

        else if( ch=='b'){
            if(!st.empty() && st.top()=='a'){
                st.push(ch);
            }
            else{
                return false;
            }
        }

        else if( ch=='c'){
            if(!st.empty() && st.top()=='b'){
                st.pop();
                if(!st.empty() && st.top()=='a'){
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

    return st.empty();
    
}

//Q6. Longest Valid Parentheses - (Leetcode 32) - V.V. IMPint longestValidParentheses(string s) {
int longestValidParentheses(string s) { // TC : O(n) SC : O(n)

    stack<int> st;
    st.push(-1);

    int maxilen = 0;

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        if (ch == '(') {
            st.push(i);
        } else {
            st.pop();
            if (st.empty()) {
                st.push(i);
            } else {
                int len = i - st.top();
                maxilen = max(len, maxilen);
            }
        }
    }

    return maxilen;
}


// Q7/ Decode String - (Leetcode 394) - V.V IMP
string decodeString(string s) { // TC : O(n) SC : O(n)
    stack<string> st;

    for(auto ch:s){
        if(ch==']'){
            // Finding String to Repeat
            string stringtoRepeat = "";
            while(!st.empty() && st.top()!="["){
                string top = st.top();
                stringtoRepeat += top;
                st.pop();
            }

            st.pop(); // This removes the opening bracket
            
            // Finding Numeric String
            string numericString = "";
            while (!st.empty() && isdigit(st.top()[0])) {
                numericString += st.top();
                st.pop();
            }
            reverse(numericString.begin(), numericString.end());
            int n = stoi(numericString);   

            // Final Decoding of current string
            string currentdecode = "";
            while(n--){
                currentdecode += stringtoRepeat; 
            }
            st.push(currentdecode);
        }
        else{
            string temp(1,ch); // Turn the char into string
            st.push(temp);
        }
    }

    string ans = "";
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(),ans.end());

    return ans;
}

// Q8. Simplify Path - (Leetcode 71)
void reverseStack(stack<string> &st,string &ans){ // TC : O(n) SC : O(n)
    if(st.empty()){ // Base Call
        return;
    }

    string minPath = st.top(); // Processing
    st.pop();

    reverseStack(st,ans); // Recursive Call
    ans+=minPath;
}

string simplifyPath(string path) { // TC : O(n) SC : O(n)
    stack<string> st;

    int i = 0;
    while(i<path.size()){
        int start = i;
        int end = i+1;

        while(end < path.size() && path[end] != '/'){ // This will go on till end will be on the next open slash
            end++;
        }

        // Now, we have the first subsection between start and end
        string minPath = path.substr(start,end-start);

        i = end; // Move to next open slash

        if(minPath=="/" || minPath=="/."){
            continue;
        }

        if(minPath!="/.."){
            st.push(minPath);
        }
        else if(!st.empty()){ // Means we are to go back a directory
            st.pop();
        }
    }

    string ans = st.empty()?"/":""; // If stack is empty, ans is root directory
    reverseStack(st,ans);
    return ans;
}

// Q9. Maximal Rectangle - (Leetcode 85) - V.V.V.V IMP
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

int maximalRectangle(vector<vector<char>>& matrix) { // TC : O(n*m) SC : O(n*m)
    // First, we convert the char matrix into int matrix
    vector<vector<int>> v;

    int n = matrix.size();
    int m = matrix[0].size();

    for(int i=0;i<n;++i){
        vector<int> t;
        for(int j=0;j<m;++j){
            t.push_back(matrix[i][j] - '0'); // Converts char to int
        }
        v.push_back(t);
    }

    int area = largestRectangleArea(v[0]);

    for(int i=1;i<n;++i){ // Start from 1 as 0th row is considered already
        for(int j=0;j<m;++j){
            // Here, we update the previous row with current row, given the '0' condition of the last row
            if(v[i][j]){
                v[i][j] += v[i-1][j]; // If it is not 0, we add the previous row
            }
            else{
                v[i][j] = 0; // If it is 0, means hist bar cannot exist hence set it to 0
            }
        }
        area = max(area,largestRectangleArea(v[i]));
    }

    return area;
}

// Q10. Daily Temperatures - (Leetcode 739)
vector<int> dailyTemperatures(vector<int>& temperatures) { // TC : O(n) SC : O(n)
    // Will be done using the logic of Next Greater Element
    vector<int> ans(temperatures.size(),0);
    stack<int> st;

    for(int i=0;i<temperatures.size();++i){
        while(!st.empty() && temperatures[i]>temperatures[st.top()]){
            ans[st.top()] = i - st.top(); // Stores the index in ans of no. of days to wait till next temp
            st.pop();
        }
        st.push(i);
    } 
    return ans;
}

// Q11. Minimum Add to Make Parentheses Valid - (Leetcode 921) - V.V IMP
int minAddToMakeValid(string s) { // TC : O(n) SC : O(n)
    stack<char> st;
    int ans = 0;

    for(auto ch: s){
        if(ch=='('){
            st.push(ch);
            ans++;
        }
        else{
            if(!st.empty()){
                st.pop();
                ans--;
            }
            else{ 
                ans++; // Means only closing is coming in an empty stack, means faulty bracket
            }
        }
    }

    return ans;
}

// Q12. Remove K Digits - (Leetcode 402) - V.V.V. IMP
string removeKdigits(string num, int k) { // TC : O(n) SC : O(n)
    stack<char> st;
    string ans = "";

    for(auto digit:num){
        if(k>0){
            while(!st.empty() && st.top() > digit){
                st.pop();
                k--;
                if(k==0){
                    break;
                }
            }
        }
        st.push(digit);
    }

    // In case it DID NOT Remove K elements
    if(k>0){
        while(!st.empty() && k){
            st.pop();
            k--;
        }
    }

    while(!st.empty()){ // Stores elements of Stack in Reverse
        ans.push_back(st.top());
        st.pop();
    }

    // Removing all Leading Zeros, as they will not be needed in final Ans
    while(ans.size()>0 && ans.back()=='0'){
        ans.pop_back();
    }

    reverse(ans.begin(),ans.end());
    return ans==""?"0":ans;
}

// Q13. Design Browser History - (Leetcode 1472) - V.V.V.V IMP
class BrowserHistory {
    stack<string> BrowserStack;stack<string> ForwardStack;
public:
    BrowserHistory(string homepage) {
        BrowserStack.push(homepage);
    }
    
    void visit(string url) {
        BrowserStack.push(url);
        while(!ForwardStack.empty()){
            ForwardStack.pop();
        }
    }
    
    string back(int steps) {
        while(steps){
            if(BrowserStack.size()<=1){
                break;
            }
            ForwardStack.push(BrowserStack.top());
            BrowserStack.pop();
            
            steps--;
        }
        return BrowserStack.top();
    }
    
    string forward(int steps) {
        while(steps){
            if(!ForwardStack.empty()){
                BrowserStack.push(ForwardStack.top());
                ForwardStack.pop();
                steps--;
            }
            else{
                break;
            }
            
        } 
        return BrowserStack.top();
    }
};

// Q14. Asteroid Collision - (Leetcode 735) - V.V.V.V IMP
vector<int> asteroidCollision(vector<int>& asteroids) { // TC : O(n) SC : O(n)
    stack<int> st;
    for(auto ast:asteroids){
        bool destroy = false; // To keep a track of the upcoming ast
        if(ast>0){
            st.push(ast);
        }
        else{
            if(st.empty()||(st.top()<0)){ // -ve and -ve do not collide
                st.push(ast);
            }
            else{ // Means +ve and -ve i.e. WILL COLLIDE
                while(!st.empty() && st.top()>0){ 
                    if(abs(ast)==st.top()){ // If equal so both will get destroyed
                        st.pop();
                        destroy = true;
                        break;
                    }
                    else if(abs(ast)>st.top()){ // If abs top smaller then top will not survive i.e no destruction as ast survives
                        st.pop();
                    }
                    else{ // If top bigger then it will destroy ast
                        destroy = true;
                        break;
                    }
                }

                if(!destroy){ // If new ast survives, ONLY THEN will be push it
                    st.push(ast);
                }
            }
        }
    }

    vector<int> ans(st.size(),0);
    for(int i=st.size()-1;i>=0;i--){ // Reverse the stack to obtain answer
        ans[i]= st.top();
        st.pop();
    }

    return ans;
}

// Q15. Next Greater Node in Linked List - (Leetcode 1019) - V.V.V.V IMP
vector<int> nextLargerNodes(ListNode* head) { // TC : O(n) SC : O(n)
    vector<int>ll;
    while(head){
        ll.push_back(head->val);
        head= head->next;
    }

    stack<int> st;

    for(int i=0;i<ll.size();++i){
        while(!st.empty() && ll[i]>ll[st.top()]){
            ll[st.top()] = ll[i];
            st.pop();
        }
        st.push(i); // We push the index of the greatest element
    }

    ll[ll.size()-1]=0; // We will store ans in ll only by Set last to 0

    while(!st.empty()){ // Set all Maximums to 0
        ll[st.top()]=0;
        st.pop();
    }
    
    return ll;
}

// Q16. Car Fleet - (Leetcode 853) - V.V.V.V IMP
class Car{
    public:
    int pos, speed;
    Car(int p, int s):pos(p),speed(s){}; // Initialisation List
};

static bool myComp(Car &a, Car&b){
    return a.pos < b.pos; // Sorts based on position
}

int carFleet(int target, vector<int>& position, vector<int>& speed) {
    vector<Car> cars;
    for(int i=0;i<position.size();i++){
        Car car(position[i],speed[i]); // We create this to bundle the car and speed together
        cars.push_back(car); 
    }

    sort(cars.begin(),cars.end(),myComp);

    stack<float> st;

    for(auto car:cars){
        float time = (target - car.pos)/((float)car.speed); // Main catch

        while(!st.empty() && time >= st.top()){
            st.pop();
        }
        st.push(time);
    } 

    return st.size();
}

// Q17. Car Fleet II - (Leetcode 1776) - V.V.V.V IMP
vector<double> getCollisionTimes(vector<vector<int>>& cars) { // TC : O(n) SC : O(n)
    vector<double> answers(cars.size(),-1); // Collision Time of ith Car with next Car
    stack<int> st;

    for(int i=cars.size()-1;i>=0;--i){
        // Check if car ahead is faster or equal to current car, if yes, then collision not possible
        while(!st.empty() && cars[st.top()][1] >= cars[i][1]){
            st.pop(); // If speed of car at top of stack >= current car, remove it from stack since it CANNOT COLLIDE
        } 

        // Check if collision is happening
        while(!st.empty()){
            double colTime = (double)(cars[st.top()][0] - cars[i][0]) / (cars[i][1] - cars[st.top()][1]); // S.IMP POINT
            if(answers[st.top()]==-1 || colTime<= answers[st.top()]){ // S.IMP Condition
                answers[i] = colTime;
                break;
            }
            st.pop();
        }

        st.push(i);
    }

    return answers;
}

int main(){
    
    return 0;
}