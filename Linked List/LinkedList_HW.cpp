#include <iostream>
#include <string>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct Node{
	int data;
    int val;
	struct Node * next;
	struct Node * bottom;
    struct Node * random;
	
	Node(int x){
	    data = x;
        val = x;
	    next = NULL;
	    bottom = NULL;
        random = NULL;
	}
	
};

// Q1. Merge Two Sorted Lists (Leetcode-21)

ListNode* mergeTwoLists(ListNode* left, ListNode* right) {

        // Base Cases
        if(left==NULL){
            return right;
        }
        if(right==NULL){
            return left;
        }

        ListNode *ans = new ListNode(-1);
        ListNode *mptr = ans; // mptr is the moving pointer/looper

        while(left && right){ 
            if(left->val<=right->val){
                mptr->next = left;
                mptr = left;
                left = left->next;
            }
            else{
                mptr->next = right;
                mptr = right;
                right = right->next;
            }
        }

        if(left){ 
            mptr->next = left;
        }

        if(right){
            mptr->next = right;
        }

        return ans->next;
}

// Q2. Flattening a Linked List (GFG)

Node *merge(Node* left, Node* right){ // Recursively merge two Linked List which are via bottom pointer
    // Base Cases
    if(left==NULL){
        return right;
    }
    if(right==NULL){
        return left;
    }
    
    //Processing
    Node* ans = NULL;
    
    if(left->data<=right->data){
        ans = left;
        left->bottom = merge(left->bottom,right); // Recursive Call
    }
    else{
        ans = right;
        right->bottom = merge(left, right->bottom); // Recursive Call
    }
    
    return ans;
}

Node *flatten(Node *root)
{
   // Now, we will recursively merge in reverse order
   
   if(root==NULL){ // Base Case
       return NULL;
   }
   
   Node* mergedLL = merge(root, flatten(root->next)); // Recursive Call (Processing is the merge function)
   
   return mergedLL;
   
}

// Q3. Copy List with Random Pointer (Leetcode-138)

// METHOD 1: Using Hashing (Time: O(N), Space: O(N))

Node* mapHelper(Node* head,unordered_map<Node*,Node*> &mp){ 
    // Function to create the map of old to new pointer and store in the given map

    // Base Case
    if(head==NULL){
        return NULL;
    }

    // Processing
    Node *newhead = new Node(head->val);

    mp[head] = newhead; 

    newhead->next = mapHelper(head->next,mp); // Recursive Call 

    if(head->random){ // At the same time, we assign the random of the new copied LL
        newhead->random = mp[head->random];
    }

    return newhead;
}

Node* copyRandomList(Node* head) {
    unordered_map<Node*,Node*> mp;
    return mapHelper(head,mp);
}

// METHOD 2: Without Hashing (Time: O(N), Space: O(1))

Node* copyRandomList(Node* head) {
    if(head==NULL){
        return NULL;
    }
    // Step1: Clone A to A'

    Node* it = head; //Looper

    while(it){
        Node* clonedNode = new Node(it->val);
        clonedNode->next = it->next;
        it->next = clonedNode;
        it= it->next->next;
    }

    // Step2: Assign random links on A' with the help of A
    it = head; //Looper

    while(it){
        Node * clonedNode = it->next;
        clonedNode->random = it->random ? it->random->next:NULL;
        it = it->next->next;
    }

    // Step3: Detach A' from A
    it = head; //Looper
    Node* clonedHead = it->next; //Ans i.e. head of new copied LL

    while(it){
        Node* clonedNode = it->next;
        it->next = it->next->next; // Dettaching Old LL

        if(clonedNode->next){ // Dettaching New LL
            clonedNode->next = clonedNode->next->next;
        }

        it = it->next;
    }

    return clonedHead;

}

// Q4. Rotate List (Leetcode-61)
int getLength(ListNode* head){
    if(head==NULL){
        return NULL;
    }

    ListNode * temp = head;
    int count = 0;

    while(temp!= NULL){ 
        count++;
        temp = temp->next; 
    }

    return count;
}

ListNode* rotateRight(ListNode* head, int k) {
    if(head==NULL){
        return NULL;
    }

    int len = getLength(head);

    if(k%len==0){
        return head;
    }

    else{
        ListNode* temp = head; //Looper
        int pos = len - (k%len) - 1;
        while(pos!=0){
            temp = temp->next;
            pos--;
        }

        ListNode* newHead = temp->next;
        temp->next = NULL;

        ListNode* temp2 = newHead;
        while(temp2->next!=NULL){
            temp2 = temp2->next;
        }

        temp2->next = head;

        return newHead;
    }
}

// Q5. Odd Even Linked List (Leetcode-328)
ListNode* oddEvenList(ListNode* head) {
    if(head==NULL || head->next==NULL){
        return head;
    }

    ListNode* h1 = head; // ODD INDEXED NODE LIST
    ListNode* h2 = head->next; // EVEN INDEXED NODE LIST

    ListNode* evenHead = h2;

    while(h2 && h2->next){
        h1->next = h2->next;
        h2->next = h2->next->next;

        h1 = h1->next;
        h2 = h2->next;
    }

    // the two independent prepared list has been regrouped.
    // odd. index walli list -> even index walli list
    h1->next = evenHead;
    return head;
    
}

// Q6. Double a number represented as Linked List (Leetcode-2816)

void solver(ListNode* head, int& carry){
    if(head==NULL){ // Base Case
        return;
    }

    solver(head->next,carry); // Recursive Call to traverse the list right to left

    // Processing
    int prod = (head->val * 2) + carry;
    head->val = prod%10;
    carry = prod/10;
    
}
ListNode* insertatHead(ListNode* head,int data){
    if(head==NULL){
        ListNode *newNode= new ListNode(data);
        head = newNode;
        return head;
    }
    else{
        ListNode *newNode= new ListNode(data);

        newNode->next = head;

        head = newNode;
        return head;
    }
}

ListNode* doubleIt(ListNode* head) {
    int carry = 0;
    solver(head,carry);

    if(carry!=0){
        return insertatHead(head,carry);
    }

    else{
        return head;
    }
    
}

// Q7. Find Minimum and Maximum Number of Nodes Between Critical Points (Leetcode-2048)
vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    vector<int> ans = {-1,-1}; // Default Answer

    ListNode* prevNode = head;
    ListNode* currNode = head->next;
    ListNode* nextNode = head->next->next;

    if(!prevNode) return ans;
    if(!currNode) return ans;
    if(!nextNode) return ans;

    int firstCP = -1;
    int lastCP = -1;

    int minDist = INT_MAX;
    int maxDist = INT_MIN;

    int i = 1;

    while(nextNode){
        bool isCP = (( currNode->val > prevNode->val && currNode->val > nextNode->val)
                    || (currNode->val<prevNode->val && currNode->val<nextNode->val))
                    ? true:false;
        if(isCP && firstCP == -1){
            firstCP = i;
            lastCP = i;
        }
        else if(isCP){
            minDist = min(minDist,i-lastCP);
            lastCP = i;
        }
        ++i;
        prevNode = prevNode->next;
        currNode = currNode->next;
        nextNode = nextNode->next; 
    }

    if(firstCP==lastCP){
        return ans;
    }
    else{
        ans[0] = minDist;
        ans[1] = lastCP-firstCP;
    }

    return ans;
}

// Q8. Merge Nodes in between Zeros (Leetcode-2181)
ListNode* mergeNodes(ListNode* head) {
    if(!head) return NULL;

    ListNode* slow = head;
    ListNode* fast = head->next;
    ListNode* last = slow;

    int sum = 0;

    while(fast){
        if(fast->val==0){
            slow->val = sum;
            last = slow;
            slow = slow->next;
            sum = 0;
        }
        else{
            sum += fast->val;
        }
        fast = fast->next;
    }

    ListNode* temp = last->next;

    while(temp){ // To prevent memory leakage
        ListNode* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    } 

    last->next = NULL;
    return head;
}

// Q9. Swapping Nodes in a Linked List(Leetcode-1721)
ListNode* swapNodes(ListNode* head, int k) {
    // Case 1
    if(head==NULL || head->next==NULL){
        return head;
    }

    int len = getLength(head);
    int lpos = k;
    int rpos = len - k + 1;

    if(rpos<lpos){
        swap(lpos,rpos);
    }

    // Case 2 : When LPos==RPOS
    if(lpos==rpos){
        return head;
    }

    // Case 3 : When length==2
    if(len==2){
        ListNode* nextNode = head->next;

        nextNode->next = head;
        head->next = NULL;

        head=nextNode;

        return head;
    }

    // Case 4 : When LPos is at 1
    if(lpos==1){
        ListNode* lp = NULL;
        ListNode* ln = head;
        ListNode* rp = head;

        for(int i=0;i<rpos-2;++i){
            rp = rp->next;
        }

        ListNode* rn = rp->next;
        ListNode* rsave = rn->next;

        rn->next = ln->next;
        rp->next = ln;
        ln->next = rsave;
        head = rn;
        return head;
    }

    // Case 5 : If the distance between the nodes to be swapped is 0
    int noOfNodesBetweenSwap = rpos - lpos - 1;

    if(noOfNodesBetweenSwap==0){
        ListNode* lp = head;
        ListNode* ln = head;
        ListNode* rp = head;

        for(int i=0;i<lpos-2;++i){
            lp = lp->next;
        }
        ln = lp->next;

        for(int i=0;i<rpos-2;++i){
            rp = rp->next;
        }

        ListNode* rn = rp->next;
        ListNode* rsave = rn->next;

        lp->next = rp->next;
        rn->next = rp;
        rp->next = rsave;


        return head;
    }

    // Case 6: If the distance between the nodes to be swapped is > 0
    else{
        ListNode* lp = head;
        ListNode* ln = head;
        ListNode* rp = head;

        for(int i=0;i<lpos-2;++i){
            lp = lp->next;
        }
        ln = lp->next;

        for(int i=0;i<rpos-2;++i){
            rp = rp->next;
        }

        ListNode* rn = rp->next;
        ListNode* rsave = rn->next;

        lp->next = rn;
        rn->next = ln->next;
        rp->next= ln;
        ln->next = rsave;

        return head;
    }
    
}

// Q10. Given a linked list of 0s, 1s and 2s, sort it (GFG)
Node* segregate(Node *head) {
    if(!head || head->next==NULL){
        return head;
    }
    
    int count[3] = {0,0,0};
    
    Node *current = head;
    
    // Count the 0s,1s and 2s
    while(current){
        count[current->data]++;
        current = current->next;
    }
    
    current = head;
    int i = 0;
    
    while(current){
        if(count[i]==0){
            i++;
        }
        else{
            current->data = i;
            count[i]--;
            current = current->next;
        }
    }
    
    return head;
}

// Q11. Add two linked lists (Leetcode-445)
ListNode* reverseList(ListNode* head){
    ListNode* prev = NULL;

    while(head){
        ListNode* nextNode = head->next;
        head->next = prev;
        prev = head;
        head = nextNode;
    }

    return prev;
}

ListNode* adder(ListNode* l1,ListNode* l2){
    ListNode* head2 = new ListNode(0);
    ListNode* tail = head2;
    int carry = 0;

    while(l1!=NULL || l2!=NULL || carry!=0){
        int digit1 = (l1 != NULL) ? l1->val:0;
        int digit2 = (l2 != NULL) ? l2->val:0;

        int sum = digit1 + digit2 + carry;
        int digit = sum%10;
        carry = sum/10;

        ListNode* newNode = new ListNode(digit);
        tail->next = newNode;
        tail = tail->next;

        l1 = (l1!=NULL)? l1->next:NULL;
        l2 = (l2!=NULL)? l2->next:NULL;
    }

    ListNode* ans = head2->next;
    delete head2;
    return ans;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    l1 = reverseList(l1);
    l2 = reverseList(l2);
    ListNode* ans = adder(l1,l2);

    return reverseList(ans);

}

// Q12. Remove Zero Sum Consecutive Nodes from Linked List (Leetcode-1171)
void sanitiseMap(ListNode* curr,unordered_map<int,ListNode*> &mp,int csum){
    int temp = csum;

    while(true){
        temp += curr->val;

        if(temp==csum) break;

        mp.erase(temp);
        curr = curr->next;
    }
}

ListNode* removeZeroSumSublists(ListNode* head) {
    if(!head || (head->next==NULL && head->val==0)) return NULL;

    unordered_map<int,ListNode*>mp;

    auto it = head;
    int csum = 0;

    while(it){
        csum += it->val;
        if(csum==0){
            head = it->next;
            mp.clear();
        }
        else if(mp.find(csum)!=mp.end()){
            sanitiseMap(mp[csum]->next,mp,csum);
            mp[csum]->next = it->next;
        }
        else{
            mp[csum] = it;
        }
        it = it->next;
    }
    return head;
}

// Q13. Sort Lists using Merge Sort (Leetcode-148)
ListNode* findMid(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head->next;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* merge(ListNode* list1, ListNode* list2) {
    if(list1==NULL){
        return list2;
    }
    if(list2==NULL){
        return list1;
    }
    
    ListNode *ans = new ListNode(-1);
    ListNode *looper = ans;

    while(list1!=NULL && list2!=NULL){
        if(list1->val<=list2->val){
            looper->next = list1;
            looper = list1;
            list1 = list1->next;
        }
        else{
            looper->next = list2;
            looper = list2;
            list2 = list2->next;
        }
    }

    if(list1!=NULL){
        looper->next = list1;
    }

    if(list2!=NULL){
        looper->next = list2;
    }
    
    ans = ans->next;
    
    return ans;
}

ListNode* sortList(ListNode* head) {
    if(head==NULL || head->next==NULL){
        return head;
    }

    // First, we find the mid of the LL and create two linked lists
    ListNode *mid = findMid(head);
    ListNode *left = head;
    ListNode *right = mid->next;

    mid->next = NULL;

    // Sort both of them (recursively)
    left = sortList(left);
    right = sortList(right);

    // Merge them
    ListNode* mergeLL = merge(left,right);

    return mergeLL;

}

// Q14. Delete N Nodes after M Nodes (GFG)
void linkdelete(struct Node  *head, int M, int N){
    if(head==NULL){ // (Base Case)
        return;
    }
    
    Node *looper = head;
    for(int i=0;i<M-1;i++){
        if(looper==NULL){ // In case the looper hits NULL // (Base Case)
            return;
        }
        looper = looper->next;
    }
    
    // In case we are at NULL Node after the iteration
    if(looper==NULL){ // (Base Case)
        return;
    }
    
    Node *MthNode = looper;
    looper = MthNode->next;
    
    for(int i=0;i<N;i++){
        if(looper==NULL){
            break;
        }
        
        Node *temp = looper->next;
        delete looper;
        looper = temp;
    }
    
    MthNode->next = looper;
    
    // Now, to do the above multiple times, we can use recursion
    linkdelete(looper,M,N);
    
}

// Q15. Print nth Node from the End (Hackerrank)
int getLength(Node *head){
    int count = 0;
    Node *temp = head;
    
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    
    return count;
}

void recursiveFind(Node* head, int &n, int &ans){
    if(head==NULL){
        return;
    }
    
    recursiveFind(head->next,n,ans);
    
    if(n==1){
        ans = head->data;
    }
    n--;
    
}

int getNthFromLast(Node *head, int n){
        // Iterative Method
        int lengthLL = getLength(head);
        int position = lengthLL - n;
        
        if(position<0){
            return -1;
        }
        else{
            Node *temp = head;
            while(position!=0){
                position--;
                temp = temp->next;
            }
            return temp->data;
        }
        
    //   // Recursive Method (will HIT TLE)
    //   int ans = -1;
    //   recursiveFind(head,n,ans);
    //   return ans;
        
}

// Q16. 

// Q1. Why Quick Sort preferred for Arrays and Merge Sort for Linked Lists?

/*
1) Quick Sort in its general form is an in-place sort (i.e. it doesn’t require any extra storage) whereas merge sort requires O(N) extra storage, N denoting the array size which may be quite expensive. Allocating and de-allocating the extra space used for merge sort increases the running time of the algorithm.
2) Comparing average complexity we find that both type of sorts have O(NlogN) average complexity but the constants differ. For arrays, merge sort loses due to the use of extra O(N) storage space.
3) Most practical implementations of Quick Sort use randomized version. The randomized version has expected time complexity of O(nLogn). The worst case is possible in randomized version also, but worst case doesn’t occur for a particular pattern (like sorted array) and randomized Quick Sort works well in practice.
4) Quick Sort is also a cache friendly sorting algorithm as it has good locality of reference when used for arrays.
5) Quick Sort is also tail recursive, therefore tail call optimizations is done.
*/

/*
1) In case of linked lists the case is different mainly due to difference in memory allocation of arrays and linked lists. Unlike arrays, linked list nodes may not be adjacent in memory.
2) Unlike array, in linked list, we can insert items in the middle in O(1) extra space and O(1) time if we are given reference/pointer to the previous node. Therefore merge operation of merge sort can be implemented without extra space for linked lists.
3) In arrays, we can do random access as elements are continuous in memory. Let us say we have an integer (4-byte) array A and let the address of A[0] be x then to access A[i], we can directly access the memory at (x + i*4). Unlike arrays, we can not do random access in linked list.
4) Quick Sort requires a lot of this kind of access. In linked list to access i’th index, we have to travel each and every node from the head to i’th node as we don’t have continuous block of memory. Therefore, the overhead increases for quick sort. Merge sort accesses data sequentially and the need of random access is low
*/

/*
Quick Sort is generally preferred for arrays because it has good cache locality and can be easily implemented in-place, which means it doesn’t require any extra memory space beyond the original array. In Quick Sort, we can use the middle element as the pivot and partition the array into two sub-arrays around the pivot. This can be done by swapping elements, and the pivot can be placed in its final position in the sorted array. 

1) This process of partitioning is done recursively until the entire array is sorted. The cache locality of Quick Sort is beneficial because it minimizes the number of cache misses, which improves performance.
2) On the other hand, Merge Sort is generally preferred for linked lists because it doesn’t require random access to elements. In Merge Sort, we divide the linked list into two halves recursively until we have individual elements. Then, we merge the individual elements by comparing and linking them in a sorted order. 
3) The advantage of Merge Sort for linked lists is that it doesn’t require random access to elements, which is not efficient for linked lists since we need to traverse the list linearly. Also, Merge Sort is a stable sort, which means it maintains the relative order of equal elements in the sorted list. This is important for linked lists, where the original order of equal elements may be significant. However, Merge Sort requires extra memory space for the merge step, which can be a disadvantage in some cases.
 

Here are some advantages and disadvantages of Quick Sort and Merge Sort:

Quick Sort Advantages:

1) Fast and efficient for arrays, especially for large datasets.
2) In-place sorting which means it doesn’t require any extra memory space beyond the original array.
3) Good cache locality which minimizes the number of cache misses.
4) Easy to implement and widely used in practice.

Quick Sort Disadvantages:

1) Not stable, which means it may change the relative order of equal elements in the sorted array.
2) Worst-case time complexity is O(n^2), which occurs when the pivot is not chosen properly and the partitioning process doesn’t divide the array evenly.
3) Not suitable for linked lists, as it requires random access to elements.

Merge Sort Advantages:

1) Suitable for sorting large datasets and linked lists.
2) Stable sort which means it maintains the relative order of equal elements in the sorted list.
3) Guaranteed worst-case time complexity of O(n*log(n)).
4) Memory efficient because it doesn’t require any extra memory space beyond the original data structure.

Merge Sort Disadvantages:

1) Requires extra memory space for the merge step, which can be a disadvantage in some cases.
2) Not as efficient as Quick Sort for small datasets.
3) Not in-place sorting, which means it requires extra memory space for temporary arrays during the merging process.
*/

