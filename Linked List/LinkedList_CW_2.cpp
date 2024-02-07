#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node{ // Doubly Linked List
    public:
    
    int data; // Block which will store the data
    Node * next; // Block which will store the address of next pointer 
    Node * prev; // Block which will store the address of the previous pointer

    Node(){ // Default Ctor
        this->next = NULL; // Point this Node towards NULL (Good industry practice)
        this->prev = NULL; // Point this Node towards NULL (Good industry practice)
    }

    Node(int data){ // Parameterized Ctor
        this->data = data; // set the current data to the given parameter 
        this->next = NULL; // Point this Node towards NULL (Good industry practice)
        this->prev = NULL; // Point this Node towards NULL (Good industry practice)
    }

};

// Now, we can convert the above to a circular linked list using the below lines:-
// tail->next = head; [USE FOR CIRCULAR DOUBLY LINKED LIST ]
// head->prev = tail; [USE FOR CIRCULAR DOUBLY LINKED LIST ]

void printClockwise(Node * head){
    Node *temp = head;

    while(temp != NULL){
        cout<<"<-"<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<endl;
}

void printAntiClockwise(Node * tail){
    Node *temp = tail;

    while(temp != NULL){
        cout<<"<-"<<temp->data<<"->";
        temp = temp->prev;
    }
    cout<<endl;
}

int lengthLL(Node *head){
    Node *temp = head;

    int length = 0;

    while(temp!=NULL){
        length++;
        temp = temp->next;
    }

    return length;
}

void CreateTail(Node * head,Node * &tail){ // In case agar sirf head diya ho, create a tail pointing Null and then do this to get the tail of LL
    Node *temp = head;

    while(temp->next!=NULL){
        temp = temp->next;
    }
    tail = temp;
}

void InsertatHead(Node * &head, Node * &tail, int data){ // BY REFERENCE PASS HOGA (* &) - IMPORTANT POINT
    if(head==NULL){ // Matlab empty list
        Node *newNode = new Node(data);

        head = newNode;
        tail = newNode;

        return;
    }
    else{
        Node *newNode = new Node(data);

        newNode->next = head;
        head->prev = newNode;
        
        head = newNode;
        // head = head->prev; // Alternate approach 
    }
}

void InsertatTail(Node * &head,Node * &tail, int data){
    if(tail==NULL){ // Matlab empty list
        Node *newNode = new Node(data);

        head = newNode;
        tail = newNode;

        return;
    }
    else{
        Node *newNode = new Node(data);

        newNode->prev = tail;
        tail->next = newNode;

        tail = newNode;
        // tail = tail->next; // Alternate approach 
    }
}

void InsertatPosition(Node * &head, Node * &tail,int data,int position){
    if(head==NULL){ // Matlab empty list
        Node *newNode = new Node(data);

        head = newNode;
        tail = newNode;

        return;
    }
      
    else{
        int length = lengthLL(head);

        if(position<=1){
            InsertatHead(head, tail,data);
            return;
        }

        else if(position>length){
            InsertatTail(head,tail,data);
            return;
        }

        else{
            Node * prevNode = NULL; // To find the location - 1 of the position to be inserted
            Node * currNode = head; // To find the location of the position to be inserted

            // a->next = b;
            // b->prev = a;

            while(position!=1){
                prevNode = currNode;
                currNode = currNode->next;
                position--;
            }

            Node *newNode = new Node(data);

            prevNode->next = newNode; 
            newNode->prev = prevNode;

            newNode->next = currNode;
            currNode->prev = newNode;
            
        }
    }
}


void RemoveatPosition(Node * &head, Node * &tail, int position){
    if(head==NULL){
        cout<<"Cannot remove from an empty list."<<endl;
        return;
    }
    else{

        if(head==tail){ ////Single element special case - IMP
            Node * temp = head;

            delete temp;

            head = NULL;
            tail = NULL;

            return;
        }
        int length = lengthLL(head);

        if(position<=1){ // Matlab first element
            Node *temp = head;

            head = head->next;
            temp->next = NULL;
            head->prev = NULL;

            delete temp;

        }

        else if(position>=length){ // Matlab last element
            Node *temp = tail;

            tail = tail->prev;
            tail->next = NULL;
            temp->prev = NULL;

            delete temp;
        }
        else{ // Matlab beech ka element delete kar do
            Node * prevNode = NULL;
            Node * currNode = head;

            while(position!=1){
                prevNode = currNode;
                currNode = currNode->next;
                position--;
            }

            Node * nextNode = currNode->next;

            prevNode->next = nextNode;
            currNode->prev = NULL;
            currNode->next = NULL;
            nextNode->prev = prevNode;

            delete currNode;

        }
    }
}

void RemovefromValue(Node * &head, Node * &tail, int value){
    if(head==NULL){
        cout<<"Cannot delete from an empty list."<<endl;
        return;
    }

    Node *looper = head;
    int position = 1;

    while(looper->next != NULL){
        if(looper->data==value){
            break;
        }
        else{
            position++;
            looper = looper->next;
        }
    }

    if(looper->data!=value){
        looper = NULL;
        position = -1;
        cout<<"Value not found in list."<<endl;
        return;
    }

    RemoveatPosition(head,tail,position);
}



int main(){

    Node * first = new Node(10);
    Node * second = new Node(20);
    Node * third = new Node(30);
    Node * fourth = new Node(40);
    Node * fifth = new Node(50);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    fifth->prev = fourth;
    fourth->prev = third;
    third->prev = second;
    second->prev = first;

    Node * head = first;
    Node * tail = fifth;

    // printClockwise(head);
    // cout<<"The length of DLL is : "<<lengthLL(head)<<endl;

    // printAntiClockwise(tail);
    // cout<<"The length of DLL is : "<<lengthLL(head)<<endl;

    printClockwise(head);

    InsertatHead(head,tail,5);

    printClockwise(head);

    InsertatTail(head,tail,55);

    printClockwise(head);

    InsertatPosition(head,tail,98,4);

    printClockwise(head);

    RemoveatPosition(head,tail,1);

    printClockwise(head);

    RemovefromValue(head,tail,55);

    printClockwise(head);

    // delete first;
    // delete second;
    // delete third;
    // delete fourth;
    // delete fifth;

}