#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ListNode{ // Singly Linked List
    public:
    
    int data; // Block which will store the data
    ListNode * next; // Block which will store the address of next pointer 

    ListNode(){ // Default Ctor
        this->next = NULL; // Point this Node towards NULL (Good industry practice)
    }

    ListNode(int data){ // Parameterized Ctor
        this->data = data; // set the current data to the given parameter 
        this->next = NULL; // Point this Node towards NULL (Good industry practice)
    }

};

// Q1. Reverse Linked List (Leetcode-206)
ListNode* reverseLinkedList(ListNode* prev,ListNode* curr){
  if(curr==NULL){
    return prev;
  }

  ListNode* nextNode = curr->next;
  curr->next = prev;

  reverseLinkedList(curr,nextNode);
}

// Q2. Linked List Cycle (Leetcode-141)
bool Cycle(ListNode* &slow,ListNode* &fast){
    while(fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
            slow = slow->next;
        }

        if(slow==fast){
            return true;
        }
    }
    return false;
}

// Q3. Starting point of loop (Leetcode-142)
ListNode *detectCycle(ListNode *head) {
    ListNode* ans = NULL;
    ListNode* slowsp = head;
    ListNode* fastsp = head;

    if(!Cycle(slowsp,fastsp)){ // If no loop, return null
        return ans;
    }

    // Reinitialise slow back to head
    slowsp = head;
    while(slowsp!=fastsp){ // Keep on moving slow and fast by one, till they meet
        fastsp = fastsp->next;
        slowsp = slowsp->next;
    }

    return slowsp; // In the end, slow will be standing on the starting point of the loop
    
}

// Q4. Remove loop (GFG)
void RemoveLoop(ListNode* head){
  ListNode* staringPoint = detectCycle(head);

  ListNode* temp = head;

  while(temp->next!=staringPoint){
    temp = temp->next;
  }
  temp->next = NULL;
}

// Q5. Add 1 to a linked list (GFG)
ListNode* PlusOne(ListNode* head){
  ListNode* prev = NULL;
  ListNode* curr = head;

  head = reverseLinkedList(prev,curr);

  ListNode* temp = head;

  int carry = 0;
  while(temp->next!=NULL){
    int totalsum = temp->data + carry;
    int digit = totalsum%10;
    carry = totalsum/10;

    temp->data = digit;
    temp = temp->next;

    if(carry==0){
      break;
    }
  }

  if(carry!=0){
    int totalsum = temp->data + carry;
    int digit = totalsum%10;
    carry = totalsum/10;

    temp->data = digit;
    if(carry!=0){
      ListNode* newNode = new ListNode(carry);
      temp->next = newNode;
    }
  }


  ListNode* prev = NULL;
  ListNode* curr = head;

  head = reverseLinkedList(prev,curr);


}

// Q5. Palindrome Linked List (Leetcode-234)
ListNode* getmiddleNode(ListNode* head){
      ListNode* slow = head;
      ListNode* fast = head;

      while(fast->next!=NULL){
          fast = fast->next;
          if(fast->next!=NULL){
              fast = fast->next;
              slow = slow->next;
          }
      }
      return slow;
  }

  ListNode* reverseusingRecursion(ListNode *prevNode, ListNode *currNode){
      if(currNode==NULL){ // Base Case
          return prevNode;
      }

      // Processing
      ListNode * nextNode = currNode->next;

      currNode->next = prevNode;

      // Recursive Call
      return reverseusingRecursion(currNode,nextNode);
  }

  bool compareLinkedList(ListNode *head1, ListNode *head2){
      ListNode *temp1 = head1;
      ListNode *temp2 = head2;
      while(temp1!=NULL && temp2!=NULL ){
          if(temp1->data != temp2->data){
              return false;
          }
          else{
              temp1 = temp1->next;
              temp2 = temp2->next;
          }
      }
      return true;
  }

  bool isPalindrome(ListNode* head) {

      // Break into two halves
      ListNode* midNode = getmiddleNode(head);
      ListNode* head2 = midNode->next; // Head of second linked list

      midNode->next = NULL; // Breaking the connection of first linked list

      // Reverse the second half
      ListNode* prev = NULL;
      ListNode* curr = head2;

      head2 = reverseusingRecursion(prev,curr);

      // Compare both halves
      return compareLinkedList(head,head2);

  }

// Q6. Reverse Nodes in k-Group (Leetcode-25) - IMP
int lengthLL(ListNode* head){
      int length = 0;
      ListNode* temp = head;
      while(temp!=NULL){
          length++;
          temp = temp->next;
      }
      return length;
  }

  ListNode* reverseKGroup(ListNode* head, int k) {
      // Base Case(s)
      if(head==NULL){
          return head;
      }

      if(head->next==NULL){
          return head;
      }

      int length = lengthLL(head);

      if(length<k){
          return head;
      }
      
      //Processing -> Basically, first k items reverse kar do
      int pos = 0;
      ListNode* prev = NULL;
      ListNode* curr = head;
      ListNode* nextNode = curr->next;

      while(pos<k){
          pos++;
          nextNode = curr->next;
          curr->next = prev;
          prev = curr;
          curr = nextNode;
      }
      
      // Recursive Call
      ListNode* ans = NULL;
      
      if(nextNode!=NULL){
          ans = reverseKGroup(nextNode,k);
          head->next = ans;
      }
      return prev;
  }

// Q7. Remove Duplicates from Sorted List (Leetcode-83)
ListNode* deleteDuplicates(ListNode* head) {
      if(head==NULL){
          return head;
      }

      if(head->next==NULL){
          return head;
      }

      ListNode* temp = head;

      while(temp!=NULL){
          if(temp->next!= NULL && temp->data == temp->next->data){
              ListNode* nextNode = temp->next->next;
              temp->next = nextNode;

              // // Preventing Memory Leakage
              // nextNode->next = NULL;

              // // Now, the node "nextNode" is isolated, hence we will now delete it
              // delete nextNode;
          }
          else{
              temp = temp->next;
          }
      }

      return head;
      
  }

int main(){

    
}