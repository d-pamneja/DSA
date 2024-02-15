// Q1. What is a binary search tree?
// Ans:
/*
A binary search tree is a binary tree in which every node fits a specific ordering property: all left sub tree <= node-val < all right sub tree. 
This must be true for each node n. Yaani ki for each node n, uske left ke saare elements usse chote honge and right ke saare elements usse bade honge.
Yeh condition individual node se hi commence hoti hai, yaani ki for each node, uske left child usse chota hoga and right child usse bada hoga.
*/



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

Node* insertIntoBST(Node* &root,int val){
  // Base Case
  if(root==NULL){
    root = new Node(val);
    return root;
  }

  // Recursive Call
  if(root->data < val){
    root->right = insertIntoBST(root->right,val);
  }
  else{
    root->left = insertIntoBST(root->left,val);
  }

  return root; 
}

Node*  getMinBST(Node* root){
  if(!root){
    cout<<"No Min Value";
    return NULL;
  }

  while(root->left){
    root = root->left;
  }

  cout<<root->data;
  return root;
}

Node* getMaxBST(Node* root){
  if(!root){
    cout<<"No Max Value";
    return NULL;
  }

  while(root->right){
    root = root->right;
  }

  cout<<root->data;
  return root;
  
}

bool searchInBST(Node* root, int target){
  if(!root){
    return false;
  }

  if(root->data==target){
    return true;
  }
  
  if(root->data > target){
    return searchInBST(root->left,target);
  }
  else{
    return searchInBST(root->right,target);
  }

}

Node* deleteFromBST(Node* root,int target){
  if(!root) return NULL;

  
  if(root->data==target){ // Find the target, if found, handle deletion
    // 4 CASES of Deletion
    
    // Case 1: The node to delete has no left and right child
    if(!root->left && !root->right){
      delete root;
      return NULL;
    }

    // Case 2: The node to delete has a left child BUT no right child
    if(root->left && !root->right){
      Node *child = root->left;
      delete root;
      return child;
    }

    // Case 3: The node to delete has a right child BUT no left child
    else if(!root->left && root->right){
      Node *child = root->right;
      delete root;
      return child;
    }

    // Case 4: The node to delete has a right child AND a left child
    else{
      // Step 1. Get the MAX value of the left Sub-Tree
      Node* maxLeft = getMaxBST(root->left);

      // Step2. iss node ke left sub-tree ki max ki value ko current node ki value set kar do
      root->data = maxLeft->data;

      // Step3. Finally, actual maxLeft jaha pada hai usse delete kar do left sub tree se and uss new tree ko current node ke LEFT se attach kar do
      root->left = deleteFromBST(root->left,maxLeft->data); // Yeh recursive call bhool jata hoon, yaha par delete function kuch toh update kar raha hoga, ussi ko lagana bhi toh hai current tree se
      return root;
    }  
    
  }
  // If not found, move to left or right sub-tree as per the target  
  else if(root->data > target){
    root->left =  deleteFromBST(root->left, target); // Yeh recursive call bhool jata hoon, yaha par delete function kuch toh update kar raha hoga, ussi ko lagana bhi toh hai current tree se
  }
  else{
    root->right  = deleteFromBST(root->right, target); // Yeh recursive call bhool jata hoon, yaha par delete function kuch toh update kar raha hoga, ussi ko lagana bhi toh hai current tree se
  }

  return root;
}

// 50 30 60 25 40 70 80 55 -1

void preorder(Node* root){
  if(!root) return;

  // NLR
  cout<<root->data<<" ";
  preorder(root->left);
  preorder(root->right);
}

void inorder(Node* root){ // This will be SORTED always i.e inorder in case of BST humesha sorted hoga
  if(!root) return;

  // LNR
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}

void postorder(Node* root){
  if(!root) return;

  // LRN
  postorder(root->left);
  postorder(root->right);
  cout<<root->data<<" ";
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


void createBST(Node* &root) {
  cout << "Enter data:" << endl;
  int data;
  cin >> data;

  while(data != -1) {
    root = insertIntoBST(root, data);
    cout << "Enter data:" << endl;
    cin >> data;
  }
}

int main(){
  Node* root = NULL;
  createBST(root);
  // 50 30 20 10 60 55 70 80 -1

  cout<<"Printing Level Order :"<<endl;
  levelOrder(root);

  cout<<"Printing Pre Order :"<<endl;
  preorder(root);

  cout<<endl;
  cout<<"Printing In Order :"<<endl;
  inorder(root);

  cout<<endl;
  cout<<"Printing Post Order :"<<endl;
  postorder(root);

  // int min = INT_MAX;
  // getMinBST(root, min);
  
  // int max = INT_MIN;
  // getMaxBST(root, max);
  
  // cout<<endl;
  // cout<<"Minimum of BST : "<<min<<endl;
  // cout<<"Maximum of BST : "<<max<<endl;

  // if(searchInBST(root,20)){
  //   cout<<"Found 20"<<endl;
  // }
  // else{
  //   cout<<"Not Found"<<endl;
  // }

  // if(searchInBST(root,80)){
  //   cout<<"Found 80"<<endl;
  // }
  // else{
  //   cout<<"Not Found"<<endl;
  // }

  // if(searchInBST(root,17)){
  //   cout<<"Found 17"<<endl;
  // }
  // else{
  //   cout<<"Not Found"<<endl;
  // }

  cout<<endl;
  int target;
  cout<<"Enter the value of target : ";
  cin>>target;

  while(target!=-1){
    deleteFromBST(root, target);
    cout<<"Printing Level Order :"<<endl;
    levelOrder(root);
     
    cout<<"Enter the value of target : ";
    cin>>target;
  }
  
  

  return 0;
}