#include <iostream>
#include <stdlib.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

// Inserting at head node
void InsertAtHead(Node *&Head, int d)
{
    Node *temp = new Node(d);
    temp->next = Head;
    Head->prev = temp;
    Head = temp;
}

// Inserting at tail node
void InsertAtTail(Node *&Tail, int d)
{
    Node *temp = new Node(d);
    Tail->next = temp;
    temp->prev = Tail;
    Tail = temp;
}

//Inserting at any position in doubly linked list
void InsertAtPosition(Node* &Head, Node* &Tail, int position,int d){

    if (position==1){
        InsertAtHead(Head,d);
        return;

    }
    Node * t=Head;
    int count=1;
    while(count<position-1){
        t=t->next;
        count++;
    }

    if (t->next==NULL){
        InsertAtTail(Tail,d);
        return;

    }
    Node* temp=new Node(d);
    temp->next=t->next;
    t->next->prev=temp;
    t->next=temp;
    temp->prev=t;
    
}

//Deletion of a node in doubly linked list
void deletion(Node* &Head,int pos){
    if (pos==1){
        Node* curr=Head;
        curr->next->prev=NULL;
        Head=curr->next;
        delete curr;
           
    }
    else{
        Node* curr=Head;
        Node* prev=NULL;
        int count=1;
        while(count<pos){
            prev=curr;
            curr=curr->next;
            count++;

        }
        curr->next->prev=prev;
        prev->next=curr->next;
        curr->next=NULL;
        curr->prev=NULL;

    }

}

// Traversing double linked list
void print(Node *Head)
{
    cout << "Displaying double linked list" << endl;
    Node *temp = Head;
    while (temp)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

// Calculating length of the double linked list
int length(Node *Head)
{
    cout << "Displaying length of double linked list" << endl;
    int length = 0;
    Node *temp = Head;
    while (temp)
    {
        length++;
        temp = temp->next;
    }
    return length;
}
int main()
{
    Node *node1 = new Node(10);
    Node *Head = node1;
    Node *Tail = node1;
    print(Head);
    cout << length(Head) << endl;

    cout << "Output after inserting at head:" << endl;
    InsertAtHead(Head, 1);
    InsertAtHead(Head, 2);
    InsertAtHead(Head, 3);
    InsertAtHead(Head, 4);
    InsertAtHead(Head, 5);

    cout << "Output after inserting at tail:" << endl;
    InsertAtTail(Tail, 6);
    InsertAtTail(Tail, 7);
    InsertAtTail(Tail, 8);
    InsertAtTail(Tail, 9);
    InsertAtTail(Tail, 10);

    print(Head);


    InsertAtPosition(Head,Tail,2,200);
    print(Head);

    deletion(Head,2);
    print(Head);
}