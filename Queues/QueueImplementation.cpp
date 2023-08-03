#include<iostream>
using namespace std;

class Queue{

     public:
    int *arr;
    int qfront;
    int rear;
    int size;


    Queue(){
      size=10000;
      arr=new int[size];
      qfront=0;
      rear=0;  
    }

    void enqueue(int data){
        if (rear==size){
            cout<<"Queue is full"<<endl;
        }
        else{
            arr[rear]=data;
            rear++;
        }

    }

    int dequeue(){
        if (qfront==rear){
            return -1;
        }
        else{
            int ans=arr[qfront];
            arr[qfront]=-1;
            qfront++;
            if (qfront==rear){
                qfront=0;
                rear=0;
            }
            return ans;
        }
        
    }


    int front(){
        if (qfront==rear){
            return -1;
        }
        else{
            return arr[qfront];
        }
    }

    bool isEmpty(){
        if (qfront==rear){
            return true;

        }
        return false;
    }

};


int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    cout<<"The fornt element of the queue is :"<<q.front()<<endl;
    cout<<"Deleted element is "<<q.dequeue()<<endl;
    cout<<"The fornt element of the queue is :"<<q.front()<<endl;
}