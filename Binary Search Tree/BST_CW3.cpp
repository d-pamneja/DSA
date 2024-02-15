#include <iostream>
#include <queue>
#include <map>
#include <climits>

using namespace std;

class Node{
	public:
	int data;
	Node* left;
	Node* right;

	Node(int value) {
		this->data = value;
		this->left = NULL;
		this->right = NULL;
	}
};

Node* bstFromInorder(int inorder[], int s, int e) {
	//base case
	if(s > e) {
		return NULL;
	}

	//1 case solve krna h 
	int mid = (s+e)/2;
	int element  = inorder[mid];
	Node* root = new Node(element);

	//baaaaki recursion
	root->left = bstFromInorder(inorder, s, mid-1);
	root->right = bstFromInorder(inorder, mid+1, e);

	return root;
}

void levelOrderTraversal(Node* root ) {
	queue<Node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()) {
		Node* temp = q.front();
		q.pop();

		if(temp == NULL) {
			cout << endl;
			if(!q.empty()) {
				q.push(NULL);
			}
		}
		else {
			cout << temp->data << " ";
			if(temp->left != NULL) {
				q.push(temp->left);
			}
			if(temp->right != NULL) {
				q.push(temp->right);
			}
		}
	}
}

void printLinkedList(Node* head) {
	Node* temp = head;
	cout << "printing the entire list: " << endl;
	while(temp != NULL) {
		cout << temp->data <<"->";
		temp = temp->right;
	}
	cout << endl;
}

// Q1. Convert BST into Sorted Double Linked List (IMP-QUESTION-INTERVIEW) - V.V.V.V.V IMP

void convertBSTtoDLL(Node* root, Node* &head){
    if(root==NULL) return;

    //RNL
    convertBSTtoDLL(root->right,head);

    
    // Connecting right sub tree as doubly linked list to current node
    root->right = head; //attaching next pointer of current node to heda of LL
    if(head!=NULL) //attaching prev pointer of head of LL to current node
        head->left = root;
    head = root; //head update

    convertBSTtoDLL(root->left,head);
}

// Q2. Convert Sorted Double Linked List into BST (IMP-QUESTION-INTERVIEW) - V.V.V.V.V IMP

Node* convertDLLtoBST(Node* &head,int n){
    if(head==NULL || n<=0){
        return NULL;
    }

    // LNR

    // Here, think of the DLL as an array. So, the mid will be at n/2. If the size of DLL in n, it's mid will be at n/2
    Node* leftSubTree = convertDLLtoBST(head,n/2); 


    Node* root = head;
    // Connecting current node to previous left Sub Tree
    root->left = leftSubTree;
    // Head Update
    head = head->right;
    

    int rightSize = n-(n/2)-1; // Here, we subtract the size of left DLL and current node to get size of right DLL
    Node* rightSubTree =  convertDLLtoBST(head,rightSize); 
    // Connecting current node to next right Sub Tree
    root->right = rightSubTree;
    

    return root;
}
 


int main(){

    // int inorder[] = {10,20,30,40,50,60,70};
	// int size = 7;
	// int start = 0;
	// int end = size-1;
	// Node* root = bstFromInorder(inorder, start, end);

	// levelOrderTraversal(root);
	// Node* head = NULL;
	// convertBSTtoDLL(root, head);
	// printLinkedList(head);

    Node* first = new Node(10);
	Node* second = new Node(20);
	Node* third = new Node(30);

	first->right = second;
	second->left = first;
	second->right = third;
	third->left = second;

	Node* head = first;
	//10<->20<->30

	Node* root = convertDLLtoBST(head, 3);
	levelOrderTraversal(root);

    return 0;
}