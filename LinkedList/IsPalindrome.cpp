#include <iostream>
#include <vector>
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
/* ***************Method=1  this method is taking extra space ******************/
bool checkPalindrome(vector<int> arr)
{
    int n = arr.size();
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        if (arr[s] != arr[e])
        {
            return false;
        }

        s++;
        e--;
        return true;
    }
}
bool isPalindrome(Node *Head)
{
    vector<int> arr;

    Node *temp = Head;
    while (temp != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }

    return checkPalindrome(arr);
}

/**********************Method-2 this method does not take any extra space**************************/
Node*getMid(Node*Head){
    Node*slow=Head;
    Node*fast=Head->next;
    while(fast!=NULL   &&   fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
   return slow;

}

Node*reverse(Node*Head){
    Node*curr=Head;
    Node*prev=NULL;
    Node*next=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;

}

bool ISPALINDROME(Node*Head){
    //if list has 0 or 1 element then it is surely a palindrome
    if (Head==NULL  ||  Head->next==NULL){
        return true;

    }
    //step-1...   find middle
    Node* middle=getMid(Head);

    //step-2....  reverse list after middle node
    Node* temp=middle->next;
    middle->next=reverse(temp);
   
   // step-3....Coampre both halves
   Node*Head1=Head;
   Node*Head2=middle->next;
   while(Head2!=NULL){
    if(Head1->data!=Head2->data){
        return false;
    }
    Head1=Head1->next;
    Head2=Head2->next;
   }
  

  // step-4....repeat step-2
  temp=middle->next;
  middle->next=reverse(temp);
   return true;


}