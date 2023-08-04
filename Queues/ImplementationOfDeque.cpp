#include <iostream>
using namespace std;

// CLASS OF DEQUE
class deque
{
public:
    int *arr;
    int front;
    int rear;
    int size;

    // CONSTRUCTOR USED TO INITIALIZE THE VALUES
    deque(int n)
    {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // INSERTING FROM THE FRONT END
    bool pushfront(int x)
    {
        if ((rear + 1) % size == front)
        {
            cout << "Queue is full" << endl;
            return false;
        }
        else if (front == -1)
        {
            front = rear = 0;
        }
        else if (front == 0)
        {
            front = size - 1;
        }
        else
        {
            front--;
        }
        arr[front] = x;
        return true;
    }

    // INSERTING FROM THE REAR END
    bool pushrear(int x)
    {
        if ((rear + 1) % size == front)
        {
            cout << "Queue is full" << endl;
            return false;
        }
        else if (front == -1)
        {
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear = 0;
        }
        arr[rear] = x;
        return true;
    }

    // DELETING FROM THE FRONT END

    int popfront()
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

    // DELETING FROM THE REAR END

    int poprear()
    {
         if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int ans = arr[rear];
        arr[rear] = -1;
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (rear==0)
        {
            rear=size-1;
        }
        else
        {
            rear--;
        }

        return ans;
    }
    
};