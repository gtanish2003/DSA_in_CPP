#include <iostream>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *random;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }
};

// Method -1..using the data structure map
class solution
{
private:
    void insertAtTail(Node *Head, Node *Tail, int d)
    {
        Node *newNode = new Node(d);
        if (Head == NULL)
        {
            Head = newNode;
            Tail = newNode;
            return;
        }
        else
        {
            Tail->next = newNode;
            Tail = newNode;
        }
    }

public:
    Node *copyList(Node *Head)
    {

        // step-1..Creating of a clone lists
        Node *cloneHead = NULL;
        Node *cloneTail = NULL;
        Node *temp = Head;
        while (temp != NULL)
        {
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp->next;
        }

        // step-2..Create a map
        unordered_map<Node *, Node *> oldToNewNode;
        Node *originalNode = Head;
        Node *cloneNode = cloneHead;
        while (originalNode && cloneNode)
        {
            oldToNewNode[originalNode] = cloneNode;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }
        originalNode = Head;
        cloneNode = cloneHead;

        while (originalNode)
        {
            cloneNode->random = oldToNewNode[originalNode->random];
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }

        return cloneHead;
    }
};

/**********************************************************
 * ********************************************************
 * ********************************************************
 * ********************************************************
 * ********************************************************
 *
 * METHOD-2.   This method takes time as order of N  and
 *             space of order of 1 i.e. constant space
 *
 * ********************************************************
 * ********************************************************
 * ********************************************************
 * ********************************************************
 * ********************************************************
 */

class solution2
{

private:
    void insertAtTail(Node *&Head, Node *&Tail, int d)
    {
        Node *newNode = new Node(d);
        if (Head == NULL)
        {
            Head = newNode;
            Tail = newNode;
        }
        else
        {
            Tail->next = newNode;
            Tail = newNode;
        }
    }

public:
    Node *copylist(Node *Head)
    {
        // step-1.create a clone lists
        Node *cloneHead = NULL;
        Node *cloneTail = NULL;

        Node *temp = Head;
        while (temp)
        {
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp->next;
        }

        // step-1. clonenodes add in between original nodes
        Node *originalNode = Head;
        Node *cloneNode = cloneHead;

        while (originalNode && cloneNode)
        {
            Node *next = originalNode->next;
            originalNode->next = cloneNode;
            originalNode = next;

            next = cloneNode->next;
            cloneNode->next = originalNode;
            cloneNode = next;
        }

        // step-3. copy random pointers
          temp = Head;
        while (temp)
        {
            if (temp->next != NULL)
            {
                if (temp->random != NULL)
                {
                    temp->next->random = temp->random->next;
                }
                else
                {
                    temp->next = temp->random;
                }
            }
            temp = temp->next->next;
        }

        // step-4.revert changes in step-2

        originalNode=Head;
        cloneNode=cloneHead;
        while(originalNode  &&  cloneNode){
            originalNode->next=cloneNode->next;
            originalNode=originalNode->next;
            

            if (originalNode!=NULL){
                cloneNode->next=originalNode->next;
            }
           
            cloneNode=cloneNode->next;

        }

        // step-5.return ans

        return cloneHead;

    }
};