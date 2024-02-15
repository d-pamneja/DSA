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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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

// Q3. LCA of BST - (Leetcode 235)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // Base Case
    if(!root) return NULL;

    // Case 1 : If both are going in different directions, then current node is LCA
    if((root->val > p->val)&&(root->val < q->val)){ // Matlab P left mein hai AND Q right mein
        return root;
    }

    // Case 2 : If both are going in different directions, then current node is LCA
    if((root->val < q->val)&&(root->val > p->val)){ // Matlab Q left mein hai AND P right mein
        return root;
    }

    // Case 3 
    if((p->val<root->val)&&(q->val<root->val)){ // Matlab dono elements left sub tree mein hai 
        return lowestCommonAncestor(root->left,p,q);
    }

    // Case 4
    if((p->val>root->val)&&(q->val>root->val)){ // Matlab dono elements right sub tree mein hai 
        return lowestCommonAncestor(root->right,p,q);
    }

    return root;
    
}

// Q4. Kth Smallest Element in a BST - (Leetcode 230)
int kthSmallest(TreeNode* root, int &k) {
    if(!root) return -1;

    //LNR
    int left = kthSmallest(root->left,k);
    if(left!=-1){ // Matlab ki agar left sub tree mein koi answer mil gaya hai, wahi return kar do 
        return left ;
    }

    k--;
    if(k==0){
        return root->val;
    }

    int right = kthSmallest(root->right,k);
    if(right!=-1){ // Matlab ki agar right sub tree mein koi answer mil gaya hai, wahi return kar do
        return right;
    }

    return -1; 
}

// Q5. Two Sum IV - Input is a BST (Leetcode-653)
void inorderSort(vector<int> &inorder,TreeNode* root){
    //LNR
    if(!root) return;

    inorderSort(inorder,root->left);
    inorder.push_back(root->val);
    inorderSort(inorder,root->right);

}

bool findTarget(TreeNode* root, int k) {
    vector<int> inorder;
    inorderSort(inorder,root);

    int s = 0;
    int e = inorder.size() - 1;

    while(s<e){
        if(inorder[s]+inorder[e]==k){
            return true;
        }
        else if(inorder[s]+inorder[e]<k){
            s++;
        }
        else{
            e--;
        }
    }
    return false;
}


int main(){

  int inorder[] = {10,20,30,40,50,60,70};
  int s = 0;
  int e = 6;

  Node* root = BSTfromInorder(inorder, s, e);
  cout<<"Printing Level Order : "<<endl;
  levelOrder(root);
}