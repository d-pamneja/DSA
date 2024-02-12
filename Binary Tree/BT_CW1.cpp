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