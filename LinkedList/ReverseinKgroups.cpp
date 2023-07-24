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
void print(Node *&Head)
{
    Node *temp = Head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


Node* kReverse(Node* &Head, int k){
    //base call
    if (Head==NULL){
        return NULL;


    }

    //STEP-1.reverse first k nodes
    Node* prev=NULL;
    Node* next=NULL;
    Node*curr=Head;
    int count=0;
    while(count<k && curr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
       count++;

    }

    //STEP-2.recursion
    Head->next=kReverse(next,k);

    //STEP-3. return the node
    return prev;
    print(prev);

}


int main()
{ // Creating a new node
    Node *node1 = new Node(10);
    
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

    Head=kReverse(Head,2);
   print(Head);

    return 0;
}