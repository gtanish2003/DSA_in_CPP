#include <iostream>
using namespace std;

class CircularQueue
{
public:
    int *arr;
    int front;
    int rear;
    int size;

    // Initialoze your data structure.
    CircularQueue(int n)
    {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    // Enqueues value into the queue .Returns true if it gets pushed into the queue.
    bool enqueue(int value)
    {
        // FULL CONDITION
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            cout << "Queue is full" << endl;
            return false;
        }
        else if (front == -1)
        {

            front = rear = 0;
            arr[rear] = value;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = value;
        }
        else
        {
            rear++;
            arr[rear] = value;
        }
        return true;
    }

    // Dequeues top element from queue.Returns -1 if the stack is empty.
    int dequeue()
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }

        return ans;
    }
};

/*
REVISED ENQUEUE AND DEQUEUE OPEREATION

void enqueue(int value){
    if ((q.rear+1) %   q.size ==  q.front){
        cout<<"Queue is full"<<endl;
    }

    else{
        q.rear = (q.rear+1) % q.size;
        q.arr[q.rear]=value;
    }
}


int dequeue(){
    int x=-1;
    if (q.front==q.rear){
        cout<<"Queue is empty"<<endl;
    }

    else{
        q.front=(q.front+1)%q.size;
        x=q.arr[q.front];

    }
    return x;
}
*/