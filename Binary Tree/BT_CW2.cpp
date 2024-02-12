#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Q1. Balanced Binary Tree (LeetCode - 110)
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