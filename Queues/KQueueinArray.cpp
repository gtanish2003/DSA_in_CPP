#include <iostream>
#include <queue>
using namespace std;

class kQueue
{
public:
    int n;
    int k;
    int *arr;
    int *front;
    int *rear;
    int *next;
    int freespot;

    kQueue(int n, int k)
    {
        this->n = n;
        this->k = k;
        arr = new int[n];

        front = new int[k];
        rear = new int[k];
        // initializing front and rear with -1
        for (int i = 0; i < k; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }

        next = new int[n];
        // initializing next array
        for (int i = 0; i < n; i++)
        {
            next[i] = i + 1;
        }
        next[n - 1] = -1;

        freespot = 0;
    }

    void enqueue(int data, int qn)
    {
        // overflow
        if (freespot == -1)
        {
            cout << "No empty space is available for inserting " << endl;
            return;
        }
        // find index
        int index = freespot;

        // update freespot
        freespot = next[index];

        // check whether first element
        if (front[qn - 1] == -1)
        {
            front[qn - 1] = index;
        }
        else
        {
            // not a first element
            next[rear[qn - 1]] = index;
        }
        // update next
        next[index] = -1;
        // update rear
        rear[qn - 1] = index;
        // push array
        arr[index] = data;
    }

    int dequeue(int qn)
    {
        // checking for underflow
        if (front[qn - 1] == -1)
        {
            cout << "Queue is empty. Nothing to pop" << endl;
            return -1;
        }
        // find index to pop the element
        int index = front[qn - 1];

        // front ko aage badhao
        front[qn - 1] = next[index];

        // freespot ko manage karo
        next[index] = freespot;

        // update freespot
        freespot = index;


        return arr[index];
    }
};