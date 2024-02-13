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

// Q3. 