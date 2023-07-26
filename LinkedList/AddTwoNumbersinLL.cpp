#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;

    Node(int data){
        this->data=data;
        this->next=NULL;

    }
};

Node * reverse(Node*Head){
    Node*curr=Head;
    Node*prev=NULL;
    Node*next=NULL;

    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr->next;

    }
    return prev;
}

void insertAtTail(Node*Head,Node*Tail,int val){
    Node*temp=new Node(val);
    if (Head==NULL){
        Head=temp;
        Tail=temp;
        return;
    }
}

Node*add (Node*first,Node*second){
    int carry=0;

    Node*ansHead=NULL;
    Node*ansTail=NULL;
    while(first!=NULL   &&   second!=NULL){
        int sum=carry+first->data+second->data;
        int digit=sum%10;
        Node*temp=new Node(digit);
        insertAtTail(ansHead,ansTail,digit);
        carry=sum/10;
        first=first->next;
        second=second->next;
    }

    while(first!=NULL){
        int sum=carry+first->data;
        int digit=sum%10;
        insertAtTail(ansHead,ansTail,digit);
        carry=sum/10;
        first=first->next;
    }

    while(second!=NULL){
        int sum=carry+second->data;
        int digit=sum%10;
        insertAtTail(ansHead,ansTail,digit);
        carry=sum/10;
        second=second->next;
    }

    while(carry!=0){
        int sum=carry;
        int digit=sum%10;
        insertAtTail(ansHead,ansTail,digit);
        carry=sum/10;
    }
    return ansHead;
}

Node*addtwolists(Node*first,Node*second){
    //step-1.reverse input Linked lists

    first=reverse(first);
    second=reverse(second);


    //step-2. add two linked lists
    Node*ans=add(first,second);

    //step-3.  reverse the answer
    ans=reverse(ans);
    return ans;
}


//upar wale method ko hi solve krke likha h neeche
/**************************************************
***************************************************
***************************************************
***************************************************
***************************************************
***************************************************
****************************************************/
Node*add (Node*first,Node*second){
    int carry=0;

    Node*ansHead=NULL;
    Node*ansTail=NULL;
    while(first!=NULL   ||  second!=NULL   ||carry!=0){
        int val1=0;
        if (first!=NULL){
            val1=first->data;
        }

        int val2=0;
        if (second!=NULL){
            val2=second->data;
        }
        int sum=carry+val1+val2;
        int digit=sum%10;
        
        insertAtTail(ansHead,ansTail,digit);
        carry=sum/10;


        if (first!=NULL){
            first=first->next;
        }
       if (second!=NULL){
        second=second->next;
       }
    }

    
    return ansHead;
}
