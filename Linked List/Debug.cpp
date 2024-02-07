#include <iostream>
using namespace std;

class Node {
    public: 
      int data;
      Node* next;
};


// Q1. 
void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    Node* head = nullptr;
    Node* second = nullptr;
    Node* third = nullptr;

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = nullptr;

    printList(head);

    return 0;
}

// Ans : Initiialise via new Node() and make the variables public
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = nullptr;

    printList(head);

    return 0;
}

//Q2.
#include <iostream>

class Node {
    public:
    int data;
    Node* next;
};

void deleteNode(Node* nodeToDelete) {
    Node* temp = nodeToDelete->next;
    nodeToDelete->data = temp->data;
    nodeToDelete->next = temp;
    delete temp;
}

void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = nullptr;

    for (int i = 1; i <= 5; i++) {
        Node* newNode = new Node;
        newNode->data = i;
        newNode->next = head;
        head = newNode;
    }

    // Deleting the node with data 3
    Node* toDelete = head->next->next;
    deleteNode(toDelete);

    std::cout << "Linked List after deletion: ";
    printList(head);

    return 0;
}

//Ans : changes in format of deleteNode function
void deleteNode(Node* prevOfnodeToDelete) {
    Node* nodeToDelete = prevOfnodeToDelete->next;
    prevOfnodeToDelete->next = nodeToDelete->next;
    nodeToDelete->next = nullptr;
    delete nodeToDelete;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = nullptr;

    for (int i = 1; i <= 5; i++) {
        Node* newNode = new Node();
        newNode->data = i;
        newNode->next = head;
        head = newNode;
    }

    std::cout << "Linked List before deletion: ";
    printList(head);

    // Deleting the node with data 3
    Node* toDelete = head->next;
    deleteNode(toDelete);

    std::cout << "Linked List after deletion: ";
    printList(head);

    return 0;
}

// Q3. 
bool hasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}

// Ans : Changes in the bool cycle function
bool hasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}

int main() {
    Node* head = nullptr;

    for (int i = 1; i <= 5; i++) {
        Node* newNode = new Node;
        newNode->data = i;
        newNode->next = head;
        head = newNode;
    }

    // Creating a cycle by linking the last node to the second node
    Node* lastNode = head;
    Node* secondNode = head->next;
    while (lastNode->next != nullptr) {
        lastNode = lastNode->next;
    }
    lastNode->next=secondNode;


    if (hasCycle(head)) {
        std::cout << "Linked List has a cycle." << std::endl;
    } else {
        std::cout << "Linked List does not have a cycle." << std::endl;
    }

    return 0;
}

// Q4.
Node* reverseList(Node* head) {
    Node* prev = head;
    Node* current = head;
    Node* nextNode = head;

    while (current != nullptr) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    head = prev;
    return head;
}

// Ans : Changes in the reverse function in the initisation of prev
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* nextNode = head;

    while (current != nullptr) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    head = prev;
    return head;
}

// Q5.
Node* mergeSortedLists(Node* list1, Node* list2) {
    Node* mergedList = nullptr;
    Node* current = mergedList;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->data < list2->data) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    if (list1 != nullptr) {
        current->next = list1;
    } else {
        current->next = list2;
    }

    return mergedList->next;
}


// Ans: Changes in the Node Creation
Node* mergeSortedLists(Node* list1, Node* list2) {
    Node* mergedList = new Node;
    Node* current = mergedList;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->data < list2->data) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    if (list1 != nullptr) {
        current->next = list1;
    } else {
        current->next = list2;
    }

    return mergedList->next;
}

// Q6.
Node* findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && slow->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Ans : Change in the while loop condition
Node* findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

