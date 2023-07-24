#include <iostream>
#include <stdlib.h>
#include <map>
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

void InsertAtPosition(Node *&Head, Node *&Tail, int position, int d)
{

    if (position == 1)
    {
        InsertAtHead(Head, d);
        return;
    }
    Node *t = Head;
    int count = 1;
    while (count < position - 1)
    {
        t = t->next;
        count++;
    }

    if (t->next == NULL)
    {
        InsertAtTail(Tail, d);
        return;
    }
    Node *temp = new Node(d);
    temp->next = t->next;
    t->next = temp;
}

bool iscircular(Node *Head)
{
    if (Head == NULL)
    {
        return false;
    }

    Node *temp = Head->next;
    while (temp != NULL && temp != Head)
    {
        temp = temp->next;
    }

    if (temp == Head)
    {
        return true;
    }
    return false;
}

bool DetectLoop(Node *Head)
{
    if (Head == NULL)
    {
        return false;
    }

    map<Node *, bool> visited;

    Node *temp = Head;
    while (temp != NULL)
    {
        // cycle is present
        if (visited[temp] == true)
        {
            return true;
        }

        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

//  ************Floyds detection cycle algorithm*****************************************************//
Node * FloydDetect(Node *Head)
{
    if (Head == NULL)
    {
        return NULL;
    }
    Node *slow = Head;
    Node *fast = Head;
    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast)
        {
            fast = fast->next;
        }
        slow = slow->next;
    }
    if (slow == fast)
    {
        return slow;
    }
    return NULL;
}
//***************************************************************************************//
//*******************************Starting node of the loop ******************************//
//***************************************************************************************//

Node * beginningNode(Node * Head){
    if (Head==NULL){
        return NULL;
    }
    Node* intersection=FloydDetect(Head);
    Node * slow=Head;
    while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;
}

//***************************************************************************************//
//*******************************Removal of the loop ************************************//
//***************************************************************************************//

void removeloop(Node* Head){
    if (Head==NULL){
        return;
    }
    Node * startLoop=beginningNode(Head);
    Node* temp=startLoop;
    while(temp->next!=startLoop){
        temp=temp->next;
    }
    temp->next=NULL;
}

void print(Node *&Head)
{
    Node *temp = Head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
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

    // Insertion at any position
    InsertAtPosition(Head, Tail, 3, 1234);

    // Displaying or traversing the linked list
    print(Head);

    cout << iscircular(Head) << endl;

    cout << DetectLoop(Head) << endl;

    
    return 0;
}