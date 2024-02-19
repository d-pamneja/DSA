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
    int data;
    Node *left;
    Node *right;
};


// Q1. Balanced Binary Tree (Leetcode - 110)
// A tree is a balanced tree if at any given node, the height of left sub-tree and right sub-tree is AT MOST 1.

int Height(TreeNode* root){
    // Base Case
    if(root==NULL){
        return 0;
    }

    int leftHeight = Height(root->left);
    int rightHeight = Height(root->right);

    return 1 + max(leftHeight,rightHeight);
}

bool isBalanced(TreeNode* root) {
    if(root==NULL){ // Base Case
        return true;
    }

    bool left = isBalanced(root->left); // Take out the ans of if left sub-tree
    bool right = isBalanced(root->right); // Take out the ans of if right sub-tree

    bool finalans = (abs(Height(root->left) - Height(root->right))<=1); // This is to check the condition of the current Node

    return (finalans && left && right); // Tree will be balanced only if all three are tree

}

// Q2. Lowest Common Ancestor of a Binary Tree (Leetcode-236) - V.V.V.V IMP
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // Base Cases
    if(root==NULL) return NULL;
    if(root->val == p->val) return p;
    if(root->val == q->val) return q;

    // Recursive call
    TreeNode* left = lowestCommonAncestor(root->left,p,q);
    TreeNode* right = lowestCommonAncestor(root->right,p,q);

    // Important Conditions
    if(left==NULL && right==NULL){
        return NULL;
    }
    else if(left==NULL && right!=NULL){
        return right;
    }
    else if(left!=NULL && right==NULL){
        return left;
    }
    else { // This will be the LCA
        return root;
    }
}

// Q3. Path Sum - (Leetcode 112)
bool solver(TreeNode* root, int targetSum, int sum){
    // Base Cases
    if(root==NULL){
        return false;
    }

    sum += root->val;

    if(root->left==NULL && root->right==NULL){ // Leaf Node
        if(sum==targetSum){
            return true;
        }
        else{
            return false;
        }
    }

    // Recursive Call
    bool left = solver(root->left, targetSum, sum);
    bool right = solver(root->right, targetSum, sum);

    // Processing
    return (left||right);
}

bool hasPathSum(TreeNode* root, int targetSum) {
    int sum = 0;
    bool ans = solver(root, targetSum, sum);
    return ans;
}

// Q4. Path Sum II (Leetcode-113)
void solve(TreeNode* root, int targetSum, int sum, vector<int> temp, vector<vector<int>> &ans){
    // Base Case
    if(root==NULL){
        return;
    }

    // Processing

    // Add sum and push to temp (potential path)
    sum += root->val;
    temp.push_back(root->val);

    if(root->left==NULL && root->right==NULL){ // Leaf Node
        if(sum==targetSum){ // If true, means temp has a path, which we push to final ans
            ans.push_back(temp);
        }
        else{
            return;
        }
    }

    // Recursive Calls
    solve(root->left,targetSum,sum,temp,ans);
    solve(root->right,targetSum,sum,temp,ans);
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> ans;
    vector<int> temp;
    int sum = 0;

    solve(root,targetSum,sum,temp,ans);
    return ans;
}

// Q5. Construct Binary Tree from Inorder and Preorder Traversal (Leetcode-105) - V.V.V.V.V Interview IMP
 void CreateMapping(vector<int>& inorder,map<int,int>& mp){
    int size = inorder.size();
    for(int i=0;i<size;i++){
        mp[inorder[i]] = i;
    }
}


TreeNode* constructTreeFromPreAndInOrder(map<int,int> &ValueToIndexMap,vector<int>& preorder, vector<int>& inorder,int &preIndex,int inOrderStart,int inOrderEnd){
    // YAAD SE, PreOrderIndex needs to be passed BY REFERENCE
    // Base Case
    int size = inorder.size();
    if(preIndex >= size || inOrderStart > inOrderEnd) {
        return NULL;
    }

    // Processing

    int element = preorder[preIndex];
    preIndex++;

    TreeNode * root = new TreeNode(element);

    int position = ValueToIndexMap[element]; // Iske left mein lagengay 0 to position-1 tak ke element, iske right mein lagengay position+1 to (n-1) tak ke element

    // Recursion
    root->left = constructTreeFromPreAndInOrder(ValueToIndexMap,preorder,inorder,preIndex,inOrderStart,position-1);
    root->right = constructTreeFromPreAndInOrder(ValueToIndexMap,preorder,inorder,preIndex,position+1,inOrderEnd);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int size = preorder.size();
    int preIndex = 0; // Mein yeh bhool Jata hoon ki this will be passed by reference
    int inOrderStart = 0;
    int inOrderEnd = size - 1;

    map<int,int> ValueToIndexMap;
    CreateMapping(inorder,ValueToIndexMap);

    TreeNode* root = constructTreeFromPreAndInOrder(ValueToIndexMap,preorder,inorder,preIndex,inOrderStart,inOrderEnd);
    return root;
}

// Q6. Construct Binary Tree from Inorder and Postorder Traversal (Leetcode-106) - V.V.V.V.V Interview IMP
void CreateMapping(vector<int>& inorder,map<int,int>& mp){
    int size = inorder.size();
    for(int i=0;i<size;i++){
        mp[inorder[i]] = i;
    }
}


TreeNode* constructTreeFromPostAndInOrder(map<int,int> &ValueToIndexMap,vector<int>& postorder, vector<int>& inorder,int &postIndex,int inOrderStart,int inOrderEnd){
    // YAAD SE, PostOrderIndex needs to be passed BY REFERENCE
    // Base Case
    int size = inorder.size();
    if(postIndex <0 || inOrderStart > inOrderEnd) {
        return NULL;
    }

    // Processing

    int element = postorder[postIndex];
    postIndex--;

    TreeNode * root = new TreeNode(element);

    int position = ValueToIndexMap[element]; // Iske left mein lagengay 0 to position-1 tak ke element, iske right mein lagengay position+1 to (n-1) tak ke element

    // Recursion
    root->right = constructTreeFromPostAndInOrder(ValueToIndexMap,postorder,inorder,postIndex,position+1,inOrderEnd); // V.V.V.V IMP - In post and inorder, phele right ki Call lagti hao
    root->left = constructTreeFromPostAndInOrder(ValueToIndexMap,postorder,inorder,postIndex,inOrderStart,position-1);

    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int size = postorder.size();
    int postIndex = size - 1; // Mein yeh bhool Jata hoon ki this will be passed by reference
    int inOrderStart = 0;
    int inOrderEnd = size - 1;

    map<int,int> ValueToIndexMap;
    CreateMapping(inorder,ValueToIndexMap);

    TreeNode* root = constructTreeFromPostAndInOrder(ValueToIndexMap,postorder,inorder,postIndex,inOrderStart,inOrderEnd);
    return root;
}

// Q7. Kth Ancestor of a Node in Binary Tree (GFG)
bool solver(Node *root, int &k,int &node,int &ans){
    // Base Case
    if(root==NULL){ 
        return false;
    }

    if(root->data==node){ 
      return true;
    }
    
    // Recursive Call
    bool left = solver(root->left,k,node,ans);
    bool right = solver(root->right,k,node,ans);
  
    if(left||right){ //checks if the target node is found in either subtree. If so, it decrements k, and if k reaches 0, it sets ans to the data of the current node and returns true. If the target node is not found, it returns false
      k--;
      if(k==0){
        ans = root->data;
      }
      return true;
    }
    
    return false; 
  
}

int kthAncestor(Node *root, int k, int node)
{
    int ans = -1;
    int count = k;
    solver(root,count,node,ans);
    
    return ans;
}

