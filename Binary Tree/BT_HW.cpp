#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct Node {
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

// Q1. FW to find diameter of binary tree - (Leetcode 543) - Optimal Approach
int D = 0;

int Height(TreeNode* root){
    // Base Case
    if(root==NULL){
        return 0;
    }

    int lheight = Height(root->left);
    int rheight = Height(root->right);

    // Update Diameter
    int currD = lheight + rheight;
    D = max(D,currD);

    return max(lheight,rheight) + 1;
}

int diameterOfBinaryTree(TreeNode* root) { // Optimal Approach : TC: O(N)
    Height(root);
    return D;
}

// Q2. FW to find height balanced tree - (Leetcode 110) - Optimal Approach
bool balanced = true;

int Height(TreeNode* root){
    // Base Case
    if(root==NULL){
        return 0;
    }

    int lheight = Height(root->left);
    int rheight = Height(root->right);

    // Now, check for each node if it's balanced, if not, update the variable
    if(balanced && abs(lheight-rheight)>1){
        balanced = false; // This condition will only be checked ONCE
    }

    return max(lheight,rheight) + 1;
}

bool isBalanced(TreeNode* root) {
    Height(root);
    return balanced;
}

// Q3. Same Tree (Leetcode-100)
bool isSameTree(TreeNode* p, TreeNode* q) {
    // Base Cases
    if(p==NULL && q==NULL){
        return true;
    }
    else if(p==NULL && q!=NULL){
        return false;
    }
    else if(p!=NULL && q==NULL){
        return false;
    }

    if(p->val==q->val){ // If values are same, move simmultaneously to left and right sub-tree
        bool left = isSameTree(p->left,q->left);
        bool right = isSameTree(p->right,q->right);

        return (left&&right);
    }
    else{
        return false;
    }
    
}

// Q4. Symmetric Tree (Leetcode-101)
bool isMirror(TreeNode* p, TreeNode* q) {
    // Base Cases
    if(p==NULL && q==NULL){
        return true;
    }
    else if(p==NULL && q!=NULL){
        return false;
    }
    else if(p!=NULL && q==NULL){
        return false;
    }

    if(p->val==q->val){ // If values are same, move simmultaneously to left and right sub-tree, with alternate approach as we are comapring mirror values
        bool left = isMirror(p->left,q->right);
        bool right = isMirror(p->right,q->left);

        return (left&&right);
    }
    else{
        return false;
    }    
}

bool isSymmetric(TreeNode* root) {
    TreeNode* left = root->left;
    TreeNode* right = root->right;

    return isMirror(left,right);
    
}

// Q5. Diagonal Traversal of Binary Tree (GFG)
vector<int> diagonal(Node *root)
{
   // The catch here is that we print a node and assume that all elements to it's right are in the same diagonal
   // The elements to it's left are to be handled later so we just push them in a queue for later use
   
   vector<int> ans;
   if(!root){
       return ans;
   }
   
   queue<Node*> q;
   q.push(root);
   
   while(!q.empty()){
       Node* temp = q.front();
       q.pop();
       
       while(temp){ // This loop will print all temps in the right diagonal 
           ans.push_back(temp->val);
           if(temp->left!=NULL){ // If left exists, toh baad mein dekhte hai
               q.push(temp->left);
           }
           temp = temp->right; // Move to right
       }
   }
   
   return ans;
   
}







int main(){
    return 0;
}