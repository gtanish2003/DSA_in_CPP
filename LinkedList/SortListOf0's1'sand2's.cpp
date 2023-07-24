#include<iostream>
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
//Method1********************************************************
Node* sortList(Node* Head){
    int zerocount=0;
    int onecount=0;
    int twocount=0;

    Node* temp=Head;
    while(temp!=NULL){
        if (temp->data==0){
            zerocount++;
        }
        else if (temp->data==1){
            onecount++;
        }
        else if (temp->data==2){
            twocount++;
        }
        temp=temp->next;
    }
    temp=Head;
    while(temp!=NULL){
        if(zerocount!=0){
            temp->data=0;
            zerocount--;
        }
        if(onecount!=0){
            temp->data=0;
            onecount--;
        }
        if(twocount!=0){
            temp->data=0;
            twocount--;
        }
        temp=temp->next;
    }
    return Head;

}


//Mehod 2 **************************************************************
void insertAtTail(Node* &Tail,Node*curr){
    Tail->next=curr;
    Tail=curr;

}


Node* sortList2(Node* Head){
    Node* zeroHead=new Node(-1);
    Node* zeroTail=zeroHead;
    Node* oneHead=new Node(-1);
    Node* oneTail=oneHead;
    Node* twoHead=new Node(-1);
    Node*  twoTail=twoHead;

    Node* curr=Head;
    while(curr!=NULL){
        if(curr->data==0){
            insertAtTail(zeroTail,curr);
        }
        else if(curr->data==1){
            insertAtTail(oneTail,curr);
        }
        else if (curr->data==2){
            insertAtTail(twoTail,curr);
        }
        curr=curr->next;
    }

    //merge 3 sublist

    if(oneHead->next!=NULL){
        zeroTail->next=oneHead->next;
    }
    else{
        zeroTail->next=twoHead->next;
    }

    oneTail->next=twoHead->next;
    twoTail->next=NULL;

    //setup Head
    Head=zeroHead->next;

    //delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return Head;
}