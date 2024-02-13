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

void LevelOrderTraversalLevelWisePrint(Node *root) { // TC: O(N) SC: O(N)
  cout << endl;
  // Traverse the queue via levels (printed in different lines as per the level)
  // Here basically, we will move to next line after a level is completed

  queue<Node *> q;
  q.push(root);
  q.push(
      NULL); // We can say with guarantee that after root a level is complelete,
             // so we will push NULL which will be used as a marker

  while (!q.empty()) {
    Node *front = q.front();
    q.pop();

    if (front == NULL) {
      // If we are here, means that now, we are completely done with this level
      // and can move to next line
      cout << endl;

      // One VERY VERY Important catch, if we hit a NULL, we can say with
      // GUARANTEE that the previous Node has pushed all it's children into
      // queue, so we should insert another NULL to act as a marker for that
      // level, but we add that NULL if and only if the queue is not empty, else
      // it will become an infinite loop
      if (!q.empty()) {
        q.push(NULL);
      }

    } else {
      cout << front->val << " ";
      // Push left and right of current Node in queue Left to Right

      if (front->left != NULL) {
        q.push(front->left);
      }
      if (front->right != NULL) {
        q.push(front->right);
      }
    }
  }
}

Node *createTree() {
  cout << "Enter the value : " << endl;
  int data;
  cin >> data;

  // If the user gives any value apart from -1, we put that as another Node.
  // Else, if they give -1, we DO NOT put another node i.e. we point current
  // node to NULL

  if (data == -1) {
    return NULL;
  }

  // Step1. Create a Node
  Node *root = new Node(data);

  // Step2. Create left sub-tree (using recursion)
  cout << "For left of Node : " << root->val << endl;
  root->left = createTree();

  // Step3. Create right sub-tree (using recursion)
  cout << "For right of Node : " << root->val << endl;
  root->right = createTree();

  return root;

  // In our code above, first the entire left subtree is made and then the
  // right, as we can see above, the code moves from left to right
}

// Q1. Left View of a Binary Tree (GFG)
void printLeftView(Node *root, int level, vector<int> &leftView) {
  if (root == NULL) {
    return;
  }

  if (level == leftView.size()) {
    // This means we are currently at the first element of a given level, so we
    // add/print that element
    leftView.push_back(root->val);
  }

  printLeftView(root->left, level + 1, leftView);
  printLeftView(root->right, level + 1, leftView);
}

// Q2. Right View of a Binary Tree (GFG)
void printRightView(Node *root, int level, vector<int> &rightView) {
  if (root == NULL) {
    return;
  }

  if (level == rightView.size()) {
    // This means we are currently at the last element of a given level, so we
    // add/print that element
    rightView.push_back(root->val);
  }

  printRightView(root->right, level + 1, rightView);
  printRightView(root->left, level + 1, rightView);
}

// Q3. Top View of a Binary Tree (GFG)
void printTopView(Node* root){
  map<int,int> hdtoNodeMap;
  queue<pair<Node*,int>> q; // This will store the Node and it's horizontal distance level (self logic). As we move left, we decrease the horizontal distance by 1 and as we move right, we increase the horizontal distance by 1

  q.push({root,0});

  while(!q.empty()){
    pair<Node*,int> temp = q.front();
    q.pop();

    Node* frontNode = temp.first;
    int hd = temp.second; // Agar iss horizontal distance ke liye answer NAHI store hua hai, toh ABH kar lo, varna agge badho

    if(hdtoNodeMap.find(hd)==hdtoNodeMap.end()){ // Agar find nahi hua, toh find function end pe aa jayega
      hdtoNodeMap[hd]=frontNode->val;
    }

    // child/children ko dekhna hai
    if(frontNode->left!=NULL){
      q.push({frontNode->left,hd-1}); // Left jatte hue horizontal level se -1 hoga
    }
    if(frontNode->right!=NULL){
      q.push({frontNode->right,hd+1}); // Left jatte hue horizontal level se +1 hoga
    }
  }

  cout<<"Printing Top View : "<<endl;
  for(auto i:hdtoNodeMap){
    cout<<i.second<<" ";
  }
  
}

int main(){

    Node *root1 = createTree();
    cout << "Printing Level Order Traversal (Line Seperated): ";
    LevelOrderTraversalLevelWisePrint(root1);
    cout << endl;
    int level = 0;
    vector<int> leftView;
    printLeftView(root1, level, leftView);

    vector<int> rightView;
    printRightView(root1, level, rightView);

    cout << "Printing Left View : ";
    for (auto el : leftView) {
        cout << el << " ";
    }

    cout << endl;

    cout << "Printing Right View : ";
    for (auto el : rightView) {
        cout << el << " ";
    }

    cout << endl;
    cout << "Printing Top View : ";
    printTopView(root1);
    return 0;
}