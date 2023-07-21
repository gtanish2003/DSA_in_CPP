#include <iostream>
#include <stdlib.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void InsertAtHead(Node *&Head, int d)
{
    Node *temp = new Node(d);
    temp->next = Head;
    Head = temp;
}

void InsertAtTail(Node *&Tail, int d)
{
    Node *temp = new Node(d);
    Tail->next = temp;
    Tail = temp;
}

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
    t->next=temp;
}

void deletion(Node* &Head,int pos){
    if (pos==1){
            Node* curr=Head;
            Head=Head->next;
            curr->next=NULL;
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
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;

    }

}

void print(Node *&Head)
{
    Node *temp = Head;
    while (temp)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int main()
{ // Creating a new node
    Node *node1 = new Node(10);
    cout << node1->data << endl;
    cout << node1->next << endl;

    // Pointing head to node1
    Node *Head = node1;

    // Pointing tail to node1
    Node *Tail = node1;

    // Insertion at head
    InsertAtHead(Head, 20);
    InsertAtHead(Head, 30);
    InsertAtHead(Head, 40);
    InsertAtHead(Head, 50);

    // Insertion at tail
    InsertAtTail(Tail, 200);
    InsertAtTail(Tail, 300);
    InsertAtTail(Tail, 400);
    InsertAtTail(Tail, 500);

    //Insertion at any position
    InsertAtPosition(Head,Tail,3,1234);

    // Displaying or traversing the linked list
    print(Head);
    
    cout<<"Deletion a node"<<endl;
    // Deleting a node
    deletion(Head,3);

    //Displaying linked list after deletion of a node
    print (Head);
    return 0;
}