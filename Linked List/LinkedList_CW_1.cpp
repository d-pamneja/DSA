#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node{ // Singly Linked List
    public:
    
    int data; // Block which will store the data
    Node * next; // Block which will store the address of next pointer 

    Node(){ // Default Ctor
        this->next = NULL; // Point this Node towards NULL (Good industry practice)
    }

    Node(int data){ // Parameterized Ctor
        this->data = data; // set the current data to the given parameter 
        this->next = NULL; // Point this Node towards NULL (Good industry practice)
    }

};

// Now, we can convert the above to a circular linked list using the below line:-
// tail->next = head; [USE FOR CIRCULAR SINGLY LINKED LIST ]

void printLL(Node * head){
    Node * temp = head;

    while(temp!= NULL){ // Jab NULL mille, ruk jao
        cout<<temp->data<<"->"; // Looping Node ka data print kar do
        temp = temp->next; // Looping Node ko uske next pe yaani agle poore Node pe point kar do 
    }
}

void CreateTail(Node * head,Node * &tail){ // In case agar sirf head diya ho, create a tail pointing Null and then do this to get the tail of LL
    Node *temp = head;

    while(temp->next!=NULL){
        temp = temp->next;
    }
    tail = temp;
}

int getlengthLL(Node * head){
    Node * temp = head;
    int count = 0;

    while(temp!= NULL){ // Jab NULL mille, ruk jao
        count++;
        temp = temp->next; // Looping Node ko uske next pe yaani agle poore Node pe point kar do 
    }

    return count;
}

// void printLLRev(Node * head){
//     Node * temp = head;

//     if(temp==NULL){ // Base Case
//         cout<<temp->data<<"<-";
//         return;
//     }
    
//     Node * x = temp->next;
//     printLLRev(x);
//     cout<<temp->data<<"<-";

// }

void InsertAtHead(Node * &head, Node * &tail,int data){ // Yaha head aur tail pass by reference hoga, not by value

    // Yaad se consider the case ki jab EMPTY LINKED LIST pass ki gayi ho
    if(head==NULL){
        Node *newNode= new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    else{
        // Create a new Node
        Node *newNode= new Node(data);

        // Point temp to the current head
        newNode->next = head;

        // Point head to our new first node
        head = newNode;
    }
    
}

void InsertAtTail(Node * &head, Node * &tail,int data){ // Yaha head aur tail pass by reference hoga, not by value
    // Yaad se consider the case ki jab EMPTY LINKED LIST pass ki gayi ho
    if(tail==NULL){
        Node *newNode= new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    else{
        // Create a new Node
        Node *newNode= new Node(data);

        // Point current tail ka next to temp
        tail->next = newNode;

        // Point tail to our new last node
        tail = newNode;
    }
}

void InsertAtPosition(Node * &head, Node * &tail,int data,int position){ // TC-> O(n)

    // Agar list hi khali hai:
    if(head==NULL){
        Node *newNode= new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }


    int length = getlengthLL(head);

    // If position ==1, matlab head pe hi insert karna hai
    if(position<=1){
        InsertAtHead(head,tail,data);
        return;
    }

    // Agar position==length+1, matlab tail pe hi insert karna hai
    else if(position>length){ //IMP - YAHA GALTI HO SAKTI HAI
        InsertAtTail(head,tail,data);
        return;
    }
    
    // Agar position >1 and position <length, then:-
    // else{ // Using curr and prev pointer
    //     Node *newNode = new Node(data);

    //     Node *prev = NULL;
    //     Node *curr = head;

    //     while(position!=1){
    //         prev = curr;
    //         curr = curr->next;
    //         position--;
    //     }

    //     prev->next = newNode;

    //     newNode->next = curr;

    // }
    else{ // Using only prev pointer
        Node *newNode = new Node(data);

        Node *prev = head;

        while(position!=2){
            position --;
            prev = prev->next;
        }

        newNode->next = prev->next;

        prev->next = newNode;
    }

}

void RemovefromLL(Node * &head, Node * &tail,int position){ // TC-> O(n)
    if(head==NULL){
        cout<<"Cannot delete from empty list"<<endl;
        return;
    }

    if(head==tail){ //Single element special case - IMP
        Node *temp = head;

        delete temp;

        head = NULL;
        tail = NULL;

        return;
    }

    int length = getlengthLL(head);

    if(position<=1){
        // Matlab delete first element
        Node *temp = head;

        head = head->next;

        temp->next = NULL; // Now, this has become a isolated node, which we can go ahead and delete

        delete temp;

        return;
    }

    else if(position>=length){
        // Matlab delete last element
        Node *temp = tail;
        Node *curr = head;

        while(curr->next!=tail){
            curr = curr->next;
        }

        curr->next = NULL; // Now, this has isolated the tail node, which we can go ahead and delete

        delete tail;

        tail = curr; // In the end, tail ko curr(new LL ke end pe) pe le aao

        return;
    }
    
    else{ // Matlab middle mein koi node delete karna hai

        Node *prev = NULL;
        Node *curr = head;


        while(position!=1){
            prev = curr;
            curr = curr->next;
            position--;
        }

        prev->next = curr->next;
        curr->next = NULL;

        delete curr;
        return;
    }
}

void RemovefromLLValue(Node * &head, Node * &tail,int value){ // Delete via value // TC-> O(n)
    if(head==NULL){
        cout<<"Cannot delete from empty list"<<endl;
        return;
    }

    int length = getlengthLL(head);

    // We use a looping variable to fetch the position of the variable
    Node *looper = head;
    int position = 1;
    while(looper->next!=NULL){
        if(looper->data==value){
            break;
        }
        else{
            looper = looper->next;
            position++;
        }
    }

    if(looper->data!=value){ // In case we do not find it, we make the function end
        looper = NULL;
        position = -1;
        cout<<"The value is not found in the LL"<<endl;
        return;
    }

    RemovefromLL(head,tail,position);
}

void deleteNode(Node** head, int key)  {    
    // If linked list is empty 
    if (*head == NULL) 
        return; 
            
    // If the list contains only a single node 
    if((*head)->data==key && (*head)->next==*head) 
    { 
        free(*head); 
        *head=NULL; 
        return; 
    } 
        
    Node *last=*head,*d; 
        
    // If head is to be deleted 
    if((*head)->data==key)  
    { 
            
        // Find the last node of the list 
        while(last->next!=*head) 
            last=last->next; 
                
        // Point last node to the next of head i.e.  
        // the second node of the list 
        last->next=(*head)->next; 
        free(*head); 
        *head=last->next; 
        return; 
    } 
        
    // Either the node to be deleted is not found  
    // or the end of list is not reached 
    while(last->next!=*head&&last->next->data!=key)  
    { 
        last=last->next; 
    } 
        
    // If node to be deleted was found 
    if(last->next->data==key)  
    { 
        d=last->next; 
        last->next=d->next; 
        free(d); 
    } 
    else
        cout<<"no such keyfound"; 
    } 

int main(){

    Node * first = new Node(10);
    Node * second = new Node(20);
    Node * third = new Node(30);
    Node * fourth = new Node(40);
    Node * fifth = new Node(50);

    first->next = second; // current node ke pointer ko aggle purre node pe point kara do
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;


    Node * head = first;
    Node * tail = fifth;

    printLL(head);
    cout<<endl;
    cout<<"The length of linked list is : "<<getlengthLL(head);
    cout<<endl;

    InsertAtHead(head,tail,5);
    printLL(head);
    cout<<endl;
    cout<<"The length of linked list is : "<<getlengthLL(head);
    cout<<endl;

    InsertAtTail(head,tail,60);
    printLL(head);
    cout<<endl;
    cout<<"The length of linked list is : "<<getlengthLL(head);
    cout<<endl;

    InsertAtPosition(head,tail,98,4);
    printLL(head);
    cout<<endl;
    cout<<"The length of linked list is : "<<getlengthLL(head);
    cout<<endl;

    RemovefromLL(head,tail,5);
    printLL(head);
    cout<<endl;
    cout<<"The length of linked list is : "<<getlengthLL(head);
    cout<<endl;

    RemovefromLLValue(head,tail,50);
    printLL(head);
    cout<<endl;
    cout<<"The length of linked list is : "<<getlengthLL(head);
    cout<<endl;

    // Node *tail2 = NULL;
    // CreateTail(head,tail2);

    // int a = tail2->data;
    // cout<<a;

    // delete first;
    // delete second;
    // delete third;
    // delete fourth;
    // delete fifth;
    // delete newNode;

    return 0;


}