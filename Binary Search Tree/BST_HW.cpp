#include <iostream>
#include <queue>
#include <map>
#include <climits>

using namespace std;

class Node{
	public:
	int data;
	Node* left;
	Node* right;

	Node(int value) {
		this->data = value;
		this->left = NULL;
		this->right = NULL;
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
    
    int canRepresentBST(int arr[], int N) {
        int min = INT_MIN;
        int max = INT_MAX;
        buildCheck(min,max,arr,N);
        
        return i==N;
    }
};

// Q9. Merge Two BSTs (GFG) - V.V.V.V.V IMP



int main(){


    return 0;
}

