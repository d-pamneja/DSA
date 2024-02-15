#include <iostream>
#include <queue>
#include <map>
#include <climits>

using namespace std;

class Node {
public:
  int data;
  Node *left;
  Node *right;

  Node(int val) {
    this->data = val;
    this->left = NULL;
    this->right = NULL;
  }
};

// Q1. Construct BST from Inorder
Node* BSTfromInorder(int inorder[],int s,int e){
  // Base Case
  if(s>e){
    return NULL;
  }

  int mid = ((e-s)/2) + s;
  Node* root = new Node(inorder[mid]);

  // Recursive Call
  root->left = BSTfromInorder(inorder, s, mid-1);
  root->right = BSTfromInorder(inorder, mid+1, e);

  return root;
}

void levelOrder(Node* root){
  queue<Node*>q;
  q.push(root);
  q.push(NULL);

  while(!q.empty()){
    Node* front = q.front();
    q.pop();

    if(front==NULL){
      cout<<endl;

      if(!q.empty()){
        q.push(NULL);
      } 
    }
    else{
      cout<<front->data<<" ";

      if(front->left){
        q.push(front->left);
      }
      if(front->right){
        q.push(front->right);
      }
    }
  }
}

// Q2. Validate BST - (Leetcode 98)
bool rangeCheckBST(Node *root, long long int lower,long long int upper){
    // Base Case
    if(!root) return true;

    // Conditional Processing 
    bool cond1 = (root->data > lower);
    bool cond2 = (root->data < upper);

    // Recursive
    bool left = rangeCheckBST(root->left, lower, root->data);
    bool right = rangeCheckBST(root->right, root->data,upper);

    return (cond1 && cond2) && (left && right);
}

bool isValidBST(Node* root) {

    // Abh, ho sakta hai ki humari values INT_MIN ya INT_MAX hi ho, toh let us increase the range shead od these both to catch edge cases
    long long int lower = -2147483677;
    long long int upper = 2147483677;

    return rangeCheckBST(root,lower,upper);

}

int main(){

  int inorder[] = {10,20,30,40,50,60,70};
  int s = 0;
  int e = 6;

  Node* root = BSTfromInorder(inorder, s, e);
  cout<<"Printing Level Order : "<<endl;
  levelOrder(root);
}