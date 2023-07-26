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

Node *findmid(Node *Head)
{
    Node *slow = Head;
    Node *fast = Head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *merge(Node *left, Node *right)
{
    if (left == NULL)
    {
        return right;
    }
    if (right == NULL)
    {
        return left;
    }

    Node *ans = new Node(-1);
    Node *temp = ans;

    // merge 2 sorted linked list
    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }

        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while (left)
    {
        temp->next = left;
        temp = left;
        left = left->next;
    }

    while (right)
    {
        temp->next = right;
        temp = right;
        right = right->next;
    }

    ans=ans->next;
    return ans;
}




Node *mergesort(Node *Head)
{

    // Base case
    if (Head == NULL || Head->next == NULL)
    {
        return Head;
    }

    // Break linked lists into two halves

    Node *mid = findmid(Head);
    Node *left = Head;
    Node *right = mid->next;
    mid->next = NULL;

    // apply recursion
    left = mergesort(left);
    right = mergesort(right);

    // merge both left and right halves
    Node *result = merge(left, right);

    // return answer
    return result;
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

    // Insertion at any position
    InsertAtPosition(Head, Tail, 3, 1234);

    // Displaying or traversing the linked list
    print(Head);

    return 0;
}