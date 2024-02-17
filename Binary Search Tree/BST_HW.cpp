#include <iostream>
#include <queue>
#include <map>
#include <stack>
#include <climits>

using namespace std;

class Node{
	public:
	int data;
	Node* left;
	Node* right;
    Node* next;

	Node(int value) {
		this->data = value;
		this->left = NULL;
		this->right = NULL;
        this->next = NULL;
	}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Q1. Inorder Successor (GFG)
Node * inOrderSuccessor(Node *root, Node *x){ // TC: O(h), SC: O(1)
    // Base Case
    if(!root||!x) return NULL;
    Node* successor = NULL;
    Node* curr = root;
    
    while(curr){
        if(curr->data>x->data){
            successor = curr;
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }
    }
    
    
    return successor;
    
}

// Q2. Inorder Predecessor (GFG)
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key){ // TC: O(h), SC: O(1)
    if(!root) return;
    Node* looper = root;
    pre = NULL;
    
    
    while(looper){
        if(looper->data < key){
            pre = looper;
            looper = looper->right;
        }
        else{
            looper = looper->left;
        }
    }
}

//Q3. BST from Preorder (Leetcode 1008)
TreeNode* build(int &i,int min,int max,vector<int>& preorder){ // TC: O(n), SC: O(h) Optimal Approach
    if(i>=preorder.size()) return NULL;
    TreeNode* root = NULL;

    if(preorder[i]>min && preorder[i]<max){
        root = new TreeNode(preorder[i]);
        i++;

        root->left = build(i,min,root->val,preorder);
        root->right = build(i,root->val,max,preorder);
    }

    return root;
}
TreeNode* bstFromPreorder(vector<int>& preorder) {
    int min = INT_MIN;
    int max = INT_MAX;

    int i = 0;
    return build(i,min,max,preorder);
    
}

// Q4. Convert BST to a Balanced BST (Leetcode 1382)
void Inorder(TreeNode* root,vector<int> &inorder){ // TC: O(n), SC: O(n)
    if(!root) return;

    // LNR
    Inorder(root->left,inorder);
    inorder.push_back(root->val);
    Inorder(root->right,inorder);
}

TreeNode* CreateTree(vector<int> &inorder,int s,int e){
    if(s>e){
        return NULL;
    }

    //NLR
    int mid = ((e-s)/2) + s;
    TreeNode* root = new TreeNode(inorder[mid]);

    root->left = CreateTree(inorder,s,mid-1);
    root->right = CreateTree(inorder,mid+1,e);

    return root;
}

TreeNode* balanceBST(TreeNode* root) {
    vector<int> inorder;
    Inorder(root,inorder);

    int s = 0;
    int e = inorder.size() - 1;

    return CreateTree(inorder,s,e);
    
}

// Q5. Find Median of BST (GFG) - (IMP) - Optimal Approach using Morris Traversal
int findNodeCount(Node* root) {
    int count = 0;

    Node* curr = root;
    while(curr){
        if(curr->left==NULL){ // Agar left nahi hai, visit the current node and move to right
            count++;
            curr = curr->right;
        }
        else{ // means left exists, toh links ko modify karte hai
            // So, first we find it's inorder predecessor i.e. done by ek baar left jao, phir right jatte raho jab tak null na ho
            Node* pred = curr->left;
            while(pred->right!=curr && pred->right){ // Matlab agar pred ka right already curr pe set NAHI hai, tabhi usko set karo
                pred = pred->right;
            }

            // if pred ka right node is NULL, then go to left AFTER establishing link of predecessor to current
            if(pred->right==NULL){
                pred->right = curr; // This basically points the pred to curr, basically a link to traverse back to it's curr. Hum pred ke iss link ki madad se vapis curr pe aa sakte hai without recursive traversal, effectively reducing travel time to O(1) instead of O(N)
                curr = curr->left;
            }
            else{ // Means left node is already visted, so we visit the right node AFTER visiting current node while REMOVING the link
                pred->right = NULL;
                count++;
                curr = curr->right;
            }
        }
    }
    return count;
}

float findActualMedian(Node* root,int n) {
    int i = 0;
    int odd1 = (n+1)/2;
    int odd1Val = -1;
    
    int even1 = n/2;
    int even1Val = -1;
    
    int even2 = (n/2) + 1;
    int even2Val = -1;

    Node* curr = root;
    while(curr){
        if(curr->left==NULL){ // Agar left nahi hai, visit the current node and move to right
            i++;
            if(i==odd1){
                odd1Val = curr->data;
            }
            if(i==even1){
                even1Val = curr->data;
            }
            if(i==even2){
                even2Val = curr->data;
            }
            curr = curr->right;
        }
        else{ // means left exists, toh links ko modify karte hai
            // So, first we find it's inorder predecessor i.e. done by ek baar left jao, phir right jatte raho jab tak null na ho
            Node* pred = curr->left;
            while(pred->right!=curr && pred->right){ // Matlab agar pred ka right already curr pe set NAHI hai, tabhi usko set karo
                pred = pred->right;
            }

            // if pred ka right node is NULL, then go to left AFTER establishing link of predecessor to current
            if(pred->right==NULL){
                pred->right = curr; // This basically points the pred to curr, basically a link to traverse back to it's curr. Hum pred ke iss link ki madad se vapis curr pe aa sakte hai without recursive traversal, effectively reducing travel time to O(1) instead of O(N)
                curr = curr->left;
            }
            else{ // Means left node is already visted, so we visit the right node AFTER visiting current node while REMOVING the link
                pred->right = NULL;
                i++;
                if(i==odd1){
                    odd1Val = curr->data;
                }
                if(i==even1){
                    even1Val = curr->data;
                }
                if(i==even2){
                    even2Val = curr->data;
                }
                curr = curr->right;
            }
        }
    }
    
    float median = 0;
    if(n&1){
        median = odd1Val;
    }
    else{
        median = (even1Val + even2Val)/2.0;
    }
    return median;
}

float findMedian(struct Node *root)
{ // TC: O(N), SC: O(1)
    int n = findNodeCount(root);
    return findActualMedian(root,n);
}

// Q6. Dead End in BST (GFG) - (IMP) - Optimal Approach
void finder(Node* root, unordered_map<int,bool> &mp,bool &ans){ // Creates a map of current node and checks if previous and next are already present in the map, if so we store them in ans
    if(!root) return;
    
    //NLR (So that by the time we reach all leaf nodes, we have already visted upepr nodes)
    mp[root->data] = true; // Visit the current node and store it in map
    if(!root->left && !root->right){
        int xp1 = root->data + 1;
        int xm1 = root->data - 1==0? root->data:root->data - 1; // Agar 0 hit ho gaya, toh uski jagah 1 se hi evaluate kar lete hai
        
        if(mp.find(xp1)!=mp.end() && mp.find(xm1)!=mp.end()){
            ans = true;
        }
        return;
    }
    
    finder(root->left,mp,ans);
    finder(root->right,mp,ans);
}


bool isDeadEnd(Node *root){ // TC: O(N), SC: O(N)
    bool ans = false;
    unordered_map<int,bool> mp; // Node and it's occurence
    finder(root,mp,ans);
    
    return ans;
    
}

// Q7. Range Sum of BST (Leetcode 938)
int rangeSumBST(TreeNode* root, int low, int high) { // TC: O(N), SC: O(H)
    if(!root) return 0;
    int ans = 0;

    bool wasinRange = false;

    // NLR Pattern

    // Case 1: Current Node in Range
    if(root->val>=low && root->val<=high){
        wasinRange = true;
        ans+=root->val;
    }

    if(wasinRange){
        ans = ans + rangeSumBST(root->left,low,high) + rangeSumBST(root->right,low,high);
    }

    // Case 2: Current Node Less Than Range, then sirf right sub tree ka ans add kar do
    else if(root->val<low){
        ans += rangeSumBST(root->right,low,high);
    }

    // Case 3 : Current Node Greater Than Range, then sirf left sub tree ka ans add kar do
    else if(root->val>high){
        ans += rangeSumBST(root->left,low,high);
    }

    return ans;
}

// Q8. Check if an array can represent Preorder Traversal of BST (GFG)
class Q8Sol {
  public:
    int i = 0;
    void buildCheck(int min,int max,int arr[],int n){
        if(i>=n) return; // Stop as at this, i will be out of bound
        
        if(arr[i]>min && arr[i]<max){ // Agar valid tree hai, toh i agge jatte jatte n ke barabar hokar ruk jayega
            int ele = arr[i];
            i++; // Means current element fits the range of BST, so move i ahead
            buildCheck(min,ele,arr,n);
            buildCheck(ele,max,arr,n);
        }
    }
    
    int canRepresentBST(int arr[], int N) { // TC: O(N), SC: O(1)
        int min = INT_MIN;
        int max = INT_MAX;
        buildCheck(min,max,arr,N);
        
        return i==N;
    }
};

// Q9. Merge Two BSTs (GFG) - V.V.V.V.V IMP
 vector<int> merge(Node *root1, Node *root2){
    // We do this my doing inorder traversal in both BST's via stacks
    stack<Node*>st1;
    stack<Node*>st2;
    
    Node* a = root1;
    Node* b = root2;
    
    vector<int> ans;
    
    bool compar = false;
    
    while(a||b||!st1.empty()||!st2.empty()){
        
        while(a){
            st1.push(a);
            a = a->left;
        }
        
        while(b){
            st2.push(b);
            b = b->left;
        }
        
        // IMPORTANT CONDITIONAL THING BELOW, yaha mein galti karta hoon
        if(st2.empty()||!st1.empty() && (st1.top()->data<=st2.top()->data)){ // Agar stack 1 mein chota element hai YA TOH stack 2 khali hi ho gaya hai, toh stack 1 se add karte raho. Par yeh dhyan rakho, ki stack 1 KHALI nahi hona chahiye. This ensures that dono stack saath mein khali ho toh kuch na karre
            auto atop = st1.top();
            ans.push_back(atop->data);
            st1.pop();
            a = atop->right;
        }
        else{ // Matlab ya toh stack B mein element hai aur A mein nahi, OR that B ka top element chota hai A ke top element se
            auto btop = st2.top();
            ans.push_back(btop->data);
            st2.pop();
            b = btop->right;
        }
    }
    
    return ans;
}


// Q10. Binary Tree to BST (GFG)
void createVector(Node* root, vector<int> &ans){
    if(!root) return;
    
    // LNR
    createVector(root->left,ans);
    ans.push_back(root->data);
    createVector(root->right,ans);
}

Node* createTreefromInorder(vector<int> ans,int s,int e){
    if(s>e) return NULL;
    int mid = ((e-s)/2) + s;
    
    Node* root = new Node(ans[mid]);
    
    root->left = createTreefromInorder(ans,s,mid-1);
    root->right = createTreefromInorder(ans,mid+1,e);
    
    return root;
    
}

Node *binaryTreeToBST (Node *root){ // TC: O(NlogN), SC: O(N)
    vector<int> ans;
    createVector(root,ans);
    sort(ans.begin(),ans.end());
    
    int s = 0;
    int e = ans.size() - 1;
    
    Node* newroot = createTreefromInorder(ans,s,e);
    return newroot;
}

// Q11. Kth Largest Element in BST (GFG)
void finder(Node* root,int &k,int &ans){
    if(!root) return;
    
    // RNL (Cause kth greatest dhund rahe hai and as BST is sorted, phele left mein jane ka)
    finder(root->right,k,ans);
    
    k--;
    if(k==0){
        ans = root->data;
        return;
    }
    
    finder(root->left,k,ans);

    
}
int kthLargest(Node *root, int K){ // TC: O(H), SC: O(1)
    int k = K;
    int ans = -1;
    finder(root,k,ans);
    
    return ans;
}

// Q12. Populate Inorder Successor for all nodes (GFG)
void InorderPoint(Node* root, Node* &successor){
    if(!root) return;
    
    // RNL (Since we are finding successor of each node, we will travel in reverse inorder, as in BST, the inroder succesor for each node from RNL will be it's previous node)
    InorderPoint(root->right,successor);
    
    root->next = successor;
    successor = root;
    
    InorderPoint(root->left,successor);
}

void populateNext(Node *root){
    // RNL 
    Node* successor = NULL;
    InorderPoint(root,successor);
}

// Q13. Brothers From Different Roots (GFG) - (IMP) - Optimal Approach
// Now, we will use the concept of Inorder and Reverse Inorder Traversal to find the pairs, 
// however, this is the best approach as it uses the property of BST and instead of using O(N) space, it uses O(H) space as we do the comparison in O(1) time via stack
// Stack apporach is very important as this reduces space complexity and is the same way how the computer does it's traversal
// DRY RUN this many times as this is thedi kheer

int countPairs(Node* root1, Node* root2, int x){
    
    stack<Node*> st1;
    stack<Node*> st2;
    
    Node* a = root1;
    Node* b = root2;
    
    int ans = 0;
    
    while(true){
        
        while(a){
            // Moving Inorder (LNR)
            st1.push(a);
            a = a->left;
        }
        
        while(b){
            // Moving Rev Inorder (RNL)
            st2.push(b);
            b = b->right;
        }
        
        if(st1.empty()||st2.empty()){
            // Means traversal complete and all nodes checked, so break it
            break;
        }
        
        auto atop = st1.top();
        auto btop = st2.top();
        
        int sum = atop->data + btop->data;
        
        if(sum == x){
            // Means ek pair mila, toh ans ko badha kar inn dono elements ko aage badha do
            ans++;
            st1.pop();
            st2.pop();
            
            // Abh jatte waqt, dono stacks mein tops ke right aur left element dalte jao taaki traversal complete ho paye jo upar likha hai 
            a = atop->right; // This is right as phele humne stack 1 mein saare left dalle (L), comparison kiya (N) aur abh jate hue 'a' mein (R) ka part complete karke jaa rahe hai
            b = btop->left;// This is left as phele humne stack 2 mein saare right dalle (R), comparison kiya (N) aur abh jate hue 'b' mein (L) ka part complete karke jaa rahe hai
        }
        else if(sum < x){
            // Yaani abh stack 1 se agge badho and jate hue uska right push kar do to complete traversal
            st1.pop();
            a = atop->right;
        }
        else{
            // Yaani abh stack 2 se agge badho and jate hue uska left push kar do to complete traversal
            st2.pop();
            b = btop->left;
        }
    }
    return ans;

}

// Q14. Flatten BST to Sorted List (GFG) - (IMP) - Optimal Approach
void flatter(Node* root,Node* &prev){
    if(!root) return;
    
    // LNR
    flatter(root->left,prev);
    
    prev->left = NULL; // Left pointer ko hatta do
    prev->right = root; // prev ke right ko current walle pe le aao, taaki prev aur curr flatten ho jaye
    prev = root; // root ko naya prev bana do, taaki yeh process end tak chal jaye
    
    flatter(root->right,prev);
}

Node *flattenBST(Node *root){ // TC: O(N), SC: O(H)
    Node* prev = new Node(-1); // DUMMY NODE, taaki ans ban jaye
    Node* dummy = prev;
    flatter(root,prev);
    
    // Now, prev will be at last element, toh prev ke left aur right dono ko NULL kar de
    prev->left = prev->right = NULL;
    
    
    // Abh, dummy node ke left ko NULL karo and right ki help se new root bana do, dummy ko isolate karke delete kar do 
    dummy->left = NULL;
    root = dummy->right;
    dummy->right = NULL;
    
    delete dummy;
    
    return root;
}

// If you want to sort the LL in decreasing order, bas right ki recursive call phele kar de, phir node ke SAME operations and left ki recursive call kar de. Basically, same code above but with RNL traversal

// Q15. Replace elements with the least Greater elements to it Right (GFG) - (V.V.IMP) - Optimal Approach
Node* insertBST(Node* root,int val,int &successor){
    if(!root) return new Node(val); // Agar waha koi element nahi, toh naya element bana kar de do
    
    if(val>=root->data){ // Agar incoming element root ki value se bada barabar hai, toh we will send it to the right of current root
        root->right = insertBST(root->right,val,successor);
    }
    else{ // Agar incoming element chota hai root ki value se, TOH HO SAKTA HAI ki yeh root humare iss element ka successor ho, so update successor and keep on moving to left
        successor = root->data;
        root->left = insertBST(root->left,val,successor);
    }
    
    return root;
}


vector<int> findLeastGreater(vector<int>& arr, int n) { // TC: O(N*logN), SC: O(N)
    vector<int> ans(n,-1); // Initialise the answer with all starting entries as -1
    Node* root = NULL;
    for(int i=n-1;i>=0;i--){ // Reverse Loop
        int successor = -1; // Is node ke liye successor initialise kar do
        root = insertBST(root,arr[i],successor); // Yeh function humare root se BST banata rahega taking each element and at the same time, yeh inserted element ke inorder successor ko bhi pakad ke le ayega
        ans[i] = successor;
    }
    
    return ans;
    
}

// Q16. Construct BST from Postorder Traversal (GFG) - (IMP) - Optimal Approach
Node* createPost(int post[],int min,int max,int &i){
   // Base Case 1 : Agar i out of bound chala jaye
   if(i<0) return NULL;
   
   // Base Case 2: Agar new element humari range mein nahi hai, toh bhi NULL
   if(post[i]<=min || post[i]>=max) return NULL;
   
   // Abh existing element ko ek node bana do
   Node* root = new Node(post[i--]);
   
   // Iss root ke left aur right bana kar (new range ke hisab se) iss root se attach kar do, since post order hai toh right phele
   root->right = createPost(post,root->data,max,i);
   root->left = createPost(post,min,root->data,i); 
   
   
   return root;
    
}

// Q17. Largest BST in a Binary Tree (GFG) - V.V.V.V.V IMP
 vector<int> check(Node* root,int &ans){
    // If root is null, return size of tree as 0, minimum value as INT_MAX and max value as INT_MIN
    if(!root) return {INT_MAX,INT_MIN,0};
    
    vector<int> left = check(root->left,ans);
    vector<int> right = check(root->right,ans);
    
    // Agar left ki max value zyada hai humare current node se YA right ki min value chotti hai humare current node se, matlab BST nahi hai apna current node, toh false dene ka
    if(left.empty() || right.empty() || left[1]>=root->data || right[0]<=root->data){
        return {INT_MIN,INT_MAX,0}; //
    }
    
    int size = left[2] + right[2]+1;
    ans = max(size,ans);
    
    
    return {min(left[0], root->data), max(right[1], root->data),size};
}

int largestBst(Node *root){ // TC: O(N), SC: O(N)
    //Your code here
    if(!root) return 0;
    

    int ans = 1;
    check(root,ans);
    
    return ans;
    
}

// Q18. Minimum Swaps to convert Binary Tree to Binary Search Tree (GFG) - V.V.V.V.V IMP
void Inorder(vector<int>&A, vector<int>&in,int index){
    // Now, we know that if it index crosses the size-1, we end the function
    if(index>=A.size()){
        return;
    }
    
    //LNR
    
    // Now, it is given that (2*index + 1) is the left child and (2*index + 2) is the right child, so we use that in our traversal
    Inorder(A,in,2*index + 1);
    in.push_back(A[index]);
    Inorder(A,in,2*index + 2);
}
int minSwaps(vector<int>&A, int n){
    // 1 - find inorder traversal of binary tree using level order traversal 
    vector<int> in;
    int index = 0;
    Inorder(A,in,index);

    // 2- make a vector with pair where pair.first will be value in inorder and pair.second will be index 
    vector<pair<int,int>> v; 
    for(int i=0;i<in.size();i++){
        pair<int,int> p;
        p.first = in[i];
        p.second = i;
        v.push_back(p);
    }
    
    // 3- then sort the vector acording to values 
    sort(v.begin(),v.end());
    
    // 4- then check the index of sorted vector it is on right postion on or not if not then swap it and make swap++
    int swaps = 0;
    for(int i=0;i<v.size();i++){
        pair<int,int> p= v[i];
        if(p.second ==i){ // Matlab agar humare vector mein yeh index sahi jagah pe pada hai toh chalte raho
            continue;
        }
        else{ // Nahi, toh matlab ek swap lagega abhi, toh count badha kar swap kar do uss jagah se jaha par dusra padha hai
            swaps++;
            swap(v[i],v[v[i].second]);
            i--; // Ek baar i ko ek step peeche lejakar phir check karo
        }
    }
    
    return swaps;
    
    
}

Node *constructTree (int post[], int size){
    int min = INT_MIN;
    int max = INT_MAX;
    
    int i = size-1;
    
    return createPost(post,min,max,i);
}


int main(){


    return 0;
}

