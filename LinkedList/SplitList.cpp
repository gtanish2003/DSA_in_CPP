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

void splitlist(Node*Head){
    Node*ref1=NULL;
    Node*ref2=NULL;
    Node*slow=Head;
    Node*fast=Head->next;
    while(fast!=Head && fast->next!=Head){
        slow=slow->next;
        fast=fast->next;
        if (fast){
            fast=fast->next;
        }

    }

    ref1=Head;
    ref2=slow->next;
    slow->next=ref1;
    
    Node* curr=ref2;
    while(curr->next!=Head){
        curr=curr->next;
    }
    curr->next=ref2;

}