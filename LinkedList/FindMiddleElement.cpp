/*************Approach 1 using the concept of getlenght method and then calculating mid element************/
/*#include <iostream>
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

int getLength(Node* Head){
    
    int count=0;
    while(Head){
        Head=Head->next;
        count++;
    }
    return count;
}

int findMiddle(Node* Head){
    int len=getLength(Head);
    int ans=len/2;
    Node* temp=Head;
    int cnt=0;
    while(cnt<ans){
        temp=temp->next;
        cnt++;
    }
    return temp->data;

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

    cout<<"The middle element of th linked list is "<<endl;
    cout<<findMiddle(Head);
    

    return 0;
}
*/





/***************************Approach 2 using the concept of fast and slow pointers**************************/




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

Node * findMiddle(Node*Head){
        if (Head==NULL||Head->next==NULL){
            return Head;

        }
        if (Head->next->next==NULL){
            return Head->next;
        }
        Node* slow=Head;
        Node* fast=Head->next;
        while(fast){
            fast=fast->next;
            if (fast){
                fast=fast->next;
            }
            slow=slow->next;
        }
        return slow;
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

    Node*ans=findMiddle(Head);
    cout<<ans->data;

    return 0;
}


