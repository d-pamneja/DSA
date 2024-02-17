#include <iostream>
#include <queue>
using namespace std;

class Node{
  public: 
    int data;
    Node* left;
    Node* right;

    Node(int val){
      this->data = val;
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

Node* createTree(){
   cout<<"Enter the value : "<<endl;
   int data;
   cin>>data;

   // If the user gives any value apart from -1, we put that as another Node. Else, if they give -1, we DO NOT put another node i.e. we point current node to NULL

   if(data==-1){
    return NULL;
   }

   // Step1. Create a Node
   Node* root = new Node(data);

   // Step2. Create left sub-tree (using recursion)
   cout<<"For left of Node : "<<root->data<<endl;
   root->left = createTree();

   // Step3. Create right sub-tree (using recursion)
   cout<<"For right of Node : "<<root->data<<endl;
   root->right = createTree();

   return root;

  // In our code above, first the entire left subtree is made and then the right, as we can see above, the code moves from left to right
}

void PreOrderTraversal(Node* root){ // TC: O(N) SC: O(n)

  // Base Case
  if(root==NULL){
    return;
  }

  // N L R

    // S1. N (Current Node)
  cout<<root->data<<" ";
    // S2. L (Left Node)
  PreOrderTraversal(root->left);
    // S3. R (Right Node)
  PreOrderTraversal(root->right);

}

void InOrderTraversal(Node* root){ // TC: O(N) SC: O(n)
  // Base Case
  if(root==NULL){
    return;
  }

  // L N R

    // S1. L (Left Node)
  InOrderTraversal(root->left);
    // S2. N (Current Node)
  cout<<root->data<<" ";
    // S3. R (Right Node)
  InOrderTraversal(root->right);

}

void PostOrderTraversal(Node* root){ // TC: O(N) SC: O(n)
  // Base Case
  if(root==NULL){
    return;
  }

  // L R N

    // S1. L (Left Node)
  PostOrderTraversal(root->left);

    // S2. R (Right Node)
  PostOrderTraversal(root->right);

    // S3. N (Current Node)
  cout<<root->data<<" ";


}

void LevelOrderTraversal(Node* root){ // TC: O(N) SC: O(N)
  // Traverse the queue via levels
  queue<Node*> q;
  q.push(root);

  while(!q.empty()){
    Node * front = q.front();
    q.pop();

    cout<<front->data<<" ";

    // Push left and right of current Node in queue Left to Right

    if(front->left!=NULL){
      q.push(front->left);
    }
    if(front->right!=NULL){
      q.push(front->right);
    }
  }

}

void LevelOrderTraversalLevelWisePrint(Node* root){ // TC: O(N) SC: O(N)
  cout<<endl;
  // Traverse the queue via levels (printed in different lines as per the level)
  // Here basically, we will move to next line after a level is completed

  queue<Node*> q;
  q.push(root);
  q.push(NULL); // We can say with guarantee that after root a level is complelete, so we will push NULL which will be used as a marker

  while(!q.empty()){
    Node * front = q.front();
    q.pop();

    if(front==NULL){
      // If we are here, means that now, we are completely done with this level and can move to next line
      cout<<endl;

      // One VERY VERY Important catch, if we hit a NULL, we can say with GUARANTEE that the previous Node has pushed all it's children into queue, so we should insert another NULL to act as a marker for that level, but we add that NULL if and only if the queue is not empty, else it will become an infinite loop
      if(!q.empty()){
        q.push(NULL);
      }

    }
    else{
      cout<<front->data<<" ";
      // Push left and right of current Node in queue Left to Right

      if(front->left!=NULL){
        q.push(front->left);
      }
      if(front->right!=NULL){
        q.push(front->right);
      }
    }
  }
}

vector<int> reverseLevelOrder(Node *root)
{
    
    vector<int> ans;
    queue<Node*>q;
    q.push(root);
    
    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        ans.push_back(front->data);
        
        if(front->right){
            q.push(front->right);
        }
        if(front->left){
            q.push(front->left);
        }
    }
    
    reverse(ans.begin(),ans.end());
    
    return ans;
}

// Q1. Height of a binary tree (Leetcode-104)
int maxDepth(TreeNode* root) {
    // here, since we are considering via node, so we initialise count with 1. If it were via edges, we would initialise count via 0
    if(root==NULL){
        return 0;
    }

    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL); // We can say with guarantee that after root a level is complelete, so we will push NULL which will be used as a marker
    int count = 1;

    while(!q.empty()){
        TreeNode * front = q.front();
        q.pop();

        if(front==NULL){
            // If we are here, means that now, we are completely done with this level and can move to next line
            cout<<endl;

            // One VERY VERY Important catch, if we hit a NULL, we can say with GUARANTEE that the previous Node has pushed all it's children into queue, so we should insert another NULL to act as a marker for that level, but we add that NULL if and only if the queue is not empty, else it will become an infinite loop
            if(!q.empty()){
                q.push(NULL);
                count++;
            }
        }
        else{
            if(front->left!=NULL){
                q.push(front->left);
            }
            if(front->right!=NULL){
                q.push(front->right);
            }
        }
    }

    return count;
    // // Recursive Way
    // // Base Case
    // if(root==NULL){
    //     return 0;
    // }

    // int leftHeight = maxDepth(root->left);
    // int rightHeight = maxDepth(root->right);
    // return max(leftHeight, rightHeight) + 1;        
}

// Q2. Diameter of a binary tree (Leetcode-543)
int diameterOfBinaryTree(TreeNode* root) { // BRUTE FORCE APPROACH if we do height via recursive method
    // Base Case
    if(root==NULL){
        return 0;
    }

    // Now, there can only be 3 of these options:
    // Option 1: Answer is entirely in left sub-tree
    // Option 2: Answer is entirely in right sub-tree
    // Option 3: Answer is in both the sub-trees

    int op1 = diameterOfBinaryTree(root->left);
    int op2 = diameterOfBinaryTree(root->right);
    int op3 = maxDepth(root->right) + maxDepth(root->left);

    return max(op1, max(op2,op3));

    
}

// Q3. Generics tree
class GenNode1{ // Using Array to store children. However, the issue here is that N should be known before hand and is fixed
  public: 
    int * arr;
    int data;

    GenNode1(int val,int size){
      arr = new int[size];
      this->data = val;
    }
};

class GenNode2{ // Here, we are using dynamic array to store children. So, the size is not fixed and can be changed as per the requirement
  public: 
    int data;
    vector<GenNode2*> children;

    GenNode2(int val){
      this->data = val;
    }
};


// Q4. READ ARTICLE: Skew tree
// A skew tree is a binary tree that has only one child of each node i.e. har node ka ek hi child node hai. It can either be left-skewed or right-skewed. 
// A left-skewed binary tree is a binary tree where every node, except the leaf node, has only one child at the left, and the right child is NULL. 
// Similarly, a right-skewed binary tree is a binary tree where every node, except the leaf node, has only one child at the right, and the left child is NULL.

// Q5. READ ARTICLE: BFS and DFS Algorithm
/*
BFS: Breadth First Search
It is a vertex-based technique for finding the shortest path in the graph.
It uses a Queue data structure that follows first in first out. In BFS, one vertex is selected at a time when it is visited and marked then its adjacent are visited and stored in the queue. It is slower than DFS. 
Agar asan bhasha me samjhe toh, BFS me hum ek node ko visit karte hai, uske adjacent nodes ko queue me daal dete hai, phir us node ko pop karke uske adjacent nodes ko queue me daal dete hai, and so on. Matlab ki level by level traverse karte hai.
*/

/*
 DFS: Depth First Search
 It is an edge-based technique. It uses the Stack data structure and performs two stages, first visited vertices are pushed into the stack, and second if there are no vertices then visited vertices are popped. 
 Agar asan bhasha me samjhe toh, DFS me hum ek node ko visit karte hai, uske adjacent nodes ko stack me daal dete hai, phir us node ko pop karke uske adjacent nodes ko stack me daal dete hai, and so on. 
 Matlab ki ek node ke adjacent nodes ko visit karte hai, phir uske adjacent nodes ke adjacent nodes ko visit karte hai, and so on. Hum level by level nahi traverse karte hai, ulta ek node ko pura traverse karte hai, answer mila toh theek, nahi toh phir uske adjacent nodes ko pura traverse karte hai, and so on.
 */


// Q6. READ ARTICLE: Complete and perfect binary tree
// Complete Binary Tree:
/*A Binary Tree is a Complete Binary Tree if all the levels are completely filled except possibly the last level and the last level has all keys as left as possible.

A complete binary tree is just like a full binary tree, but with three major differences:

1) Every level except the last level must be completely filled.
2) All the leaf elements must lean towards the left.
3) The last leaf element might not have a right sibling i.e. a complete binary tree doesn’t have to be a full binary tree

Asan bhasha me samjhe toh, complete binary tree me har level except the last level pura filled hota hai, and last level me bhi agar koi node nahi hai toh left se start hota hai, and right se end hota hai. 
*/

// Perfect Binary Tree:
/*
A Binary tree is a Perfect Binary Tree in which all the internal nodes have two children and all leaf nodes are at the same level. 
The following are examples of Perfect Binary Trees. 

A perfect binary tree is a type of binary tree in which every internal node has exactly two child nodes and all the leaf nodes are at the same level.
Asan bhasha me samjhe toh, perfect binary tree me har internal node ke 2 children hote hai, and all leaf nodes same level pe hote hai.
*/



int main() {
  Node* root1 = createTree();

  cout<<"Printing Pre Order Traversal : ";
  PreOrderTraversal(root1);
  cout<<endl;
  cout<<"Printing In Order Traversal : ";
  InOrderTraversal(root1);
  cout<<endl;
  cout<<"Printing Post Order Traversal : ";
  PostOrderTraversal(root1);
  cout<<endl;
  cout<<"Printing Level Order Traversal : ";
  LevelOrderTraversal(root1);
  cout<<endl;
  cout<<"Printing Level Order Traversal (Line Seperated): ";
  LevelOrderTraversalLevelWisePrint(root1);
  cout<<endl;
  return 0;
}