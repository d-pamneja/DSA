#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <set>
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

// Q6. Vertical Traversal of Binary Tree (Leetcode-987) V.V.V.V.Imp
vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> ans; 
    // Since we will be using big data structures, it will be better that we use them by reference when needed(if possible)
    queue<pair<TreeNode*,pair<int,int>>> q; // A pair which contains: {TreeNode,{row,col}}
    q.push({root,{0,0}}); // Root will start at origin

    map<int,map<int,multiset<int> > >mp; // {col->{row->[x,y,z,..]}} :Basically, A map which stores: {col->map<row,multiset of all values in that row (sorted)>}. Basically, it is a map sorted by col (key), where the key has another map of all sorted by rows and a multiset of all values in that row(sorted ofc).
    // We have used multiset cause the values should also be sorted. We could have used a vector and then sorted it, but then that will be done automatically by multiset

    while(!q.empty()){ // Variant of level order traversal
        auto front = q.front();
        q.pop();

        TreeNode* &node = front.first;
        auto&coordinates = front.second;
        int &row = coordinates.first;
        int &col = coordinates.second;

        mp[col][row].insert(node->val); // Map ke andar {col->{row->[x,y,z,..]}} format se entry insert kar do

        // If we go left, we do row+1,col-1
        if(node->left){
            q.push({node->left,{row+1,col-1}});
        }
        if(node->right){ // If we go right, we do row+1,col+1
            q.push({node->right,{row+1,col+1}});
        }

    }

    // Store final vertical order into answer vector
    for(auto it:mp){ // This will take all cols from left to right i.e. it is inserted in sorted order only
        auto&ColMap = it.second;
        vector<int> vLine;
        for(auto colMapIt:ColMap){ // This will take all rows from top to bottom i.e. it is inserted in sorted order only
            auto&mset = colMapIt.second;
            vLine.insert(vLine.end(),mset.begin(),mset.end()); // Jo jo bhi mset mein pada hai usse utha kar as it daal do vLine ke end tak
        }
        ans.push_back(vLine);
    }

    return ans;
}

// Q7. ZigZag Traversal of Binary Tree (Leetcode-103)
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;

    // Base Case
    if(!root){
        return ans;
    }

    queue<TreeNode*> q;
    bool LtoRDir = true;
    q.push(root);

    while(!q.empty()){
        int width = q.size(); // Width of that level
        vector<int> currLevel(width);

        for(int i=0;i<width;i++){
            TreeNode* front = q.front();
            q.pop();
            int index = LtoRDir ? i:width - i - 1; // Matlab agar direction left to right hai tabh toh normal, nahi toh index peeche se initiate kar do

            // Push current value into current level
            currLevel[index] = front->val;

            // Push left and right nodes
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }

        LtoRDir = !LtoRDir; // Basically, toggle the current direction to it's opposite one
        ans.push_back(currLevel);
    }

    return ans;
}

// Q8. Transform to Sum Tree (GFG)
int sum(Node* root){
    if(!root){
        return 0;
    }
    if(!root->left && !root->right){ // Means leaf node
        int temp = root->val;
        root->val = 0;
        return temp;
    }
    
    int lsum = sum(root->left);
    int rsum = sum(root->right);
    int temp = root->val; // Current root ka data
    
    root->val = lsum + rsum;
    return root->val + temp; 
    
}

void toSumTree(Node *node)
{
    sum(node);
} 


// Q9. K-Sum Paths/Path Sum III (Leetcode-437) - V.V.Imp
int ans = 0;

void pathFromRoot(TreeNode* root, long long sum){
    // Base Case
    if(!root) return;

    if(sum==root->val){
        ++ans;
    }

    // Recursive Call
    pathFromRoot(root->left,sum - root->val);
    pathFromRoot(root->right,sum - root->val);

}


int pathSum(TreeNode* root, long long targetSum) {
    if(root){ // NLR Traversal
        pathFromRoot(root,targetSum);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
    }
    return ans;
    
}

// Q10. Sum of longest bloodline of a tree/ Sum of nodes on the longest path from root to leaf node (GFG)
pair<int,int> height(Node *root){ // Modification of height function to store height and current sum
    if(!root){
        return {0,0};
    }
    
    auto lh = height(root->left);
    auto rh = height(root->right);
    
    int sum = root->val;
    
    if(lh.first==rh.first){
        sum+= lh.second > rh.second? lh.second : rh.second;
    }
    else if(lh.first>rh.first){
        sum+= lh.second;
    }
    else{
        sum+=rh.second;
    }
    
    return {max(lh.first,rh.first) + 1,sum};
}

int sumOfLongRootToLeafPath(Node *root)
{
    auto h = height(root);
    return h.second;
}

// Q11. Maximum sum of Non-adjacent nodes - (GFG)
pair<int,int> helper(Node* root){
    // First will store sum including the current node, second will include sum not including the current node
    if(!root) return {0,0};
    
    auto lsum = helper(root->left);
    auto rsum = helper(root->right);
    
    // Sum including the Node
    int a = root->val + lsum.second + rsum.second;
    
    // Sum NOT including the Node
    int b = max(lsum.first,lsum.second) + max(rsum.first,rsum.second);
    
    return {a,b};
}
int getMaxSum(Node *root) 
{
    // Add your code here
    auto ans = helper(root);
    return max(ans.first,ans.second);
}

// Q12. Burning Tree (GFG) - V.V.Imp
// Step1. Find the target in the tree
// Step2. Create a mapping of each node and it's parent node
// Step3. Burn the tree from the target node and keep track of the time taken to burn the tree
Node* makeNodeToParentMappingAndFindTarget(Node* root, unordered_map<Node*,Node*> &parentMap, int target){
    // Level order traversal se karte hai
    queue<Node*> q;
    Node * targetNode = NULL;
    q.push(root);
    parentMap[root] = NULL;
    
    
    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        
        if(front->val == target){ // Here, all values will be unique in tree
            targetNode = front;
        }
        
        if(front->left){
            q.push(front->left);
            parentMap[front->left]=front;
        }
        if(front->right){
            q.push(front->right);
            parentMap[front->right]=front;
        }
    }
    
    return targetNode;
}

int burnTheTree(unordered_map<Node*,Node*> &parentMap, Node* targetNode){
    unordered_map<Node*,bool> isBurnt; // Mapping of each node and whether they are burnt or not
    queue<Node*> q; // Stores the current queue which is being burned
    
    int t = 0;
    
    q.push(targetNode);
    isBurnt[targetNode] = true;
    
    while(!q.empty()){
        int size = q.size();
        bool isFireSpreaded = false;
        for(int i=0;i<size;++i){ // We are doing this for loop as each node burns left, right and parent AT THE SAME TIME, hence we will pick up 1 element from the queue and burn it across all directions possible
            Node* front = q.front();
            q.pop();
            
            if(front->left && !isBurnt[front->left]){ // If left exists and it's NOT burnt, we burn it and change it's status
                q.push(front->left);
                isBurnt[front->left] = true;
                isFireSpreaded = true;
            }
            if(front->right && !isBurnt[front->right]){ // If right exists and it's NOT burnt, we burn it and change it's status
                q.push(front->right);
                isBurnt[front->right] = true;
                isFireSpreaded = true;
            }
            if(parentMap[front] && !isBurnt[parentMap[front]]){ // If parent exists is NOT burnt, we burn it and change it's status
                q.push(parentMap[front]);
                isBurnt[parentMap[front]] = true;
                isFireSpreaded = true;
            }
        }
        
        if(isFireSpreaded){
            t++;
        }
        
    }
    
    return t;
}


int minTime(Node* root, int target) 
{
    unordered_map<Node*,Node*> parentMap;
    Node* targetNode = makeNodeToParentMappingAndFindTarget(root,parentMap,target);
    return burnTheTree(parentMap,targetNode);
}

// Q13. Find Duplicate Subtrees (Leetcode-652) - V.V.Imp
class SolQ13{
    vector<TreeNode*> ans;
unordered_map<string,int> subTreeMap; // {Encoding->Occurenece}

string preorder(TreeNode* root){ // Basically, we will create string encodings of each node to make them and their respective sub-trees unique
    if(!root) return "N"; // Meaning Null

    string curr = to_string(root->val);
    string left = preorder(root->left);
    string right = preorder(root->right);

    string Encoded = curr + "," + left + "," + right;

    if(subTreeMap.find(Encoded)!=subTreeMap.end()){ // If this condition is true, means this EXACT encoded string has entered the map before i.e. exists in map
        if(subTreeMap[Encoded]==1){ // S.IMP: If it exists only once before, i.e. this is the second occurence, only then is it duplicate and we add it to ans. 
            ans.push_back(root); // Since we might have multiple duplicates, we only store ans at the first occurence of a duplicate i.e. same entry twice to satisfy the constraints of the question
        }
        subTreeMap[Encoded]++;
    }
    else{ // Does not exist in map so create it
        subTreeMap[Encoded] = 1;
    }

    return Encoded;
}

vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    preorder(root);
    return ans;
}
};

// Q14. Morris Traversal (GFG) - V.V.V.V.Imp



int main(){
    return 0;
}