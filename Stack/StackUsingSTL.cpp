#include <iostream>
#include <stack>
using namespace std;

class Stack{
    public:
    int top;
    int *arr;
    int size;

    Stack(int size){
        this->size=size;
        arr=new int [size];
        top=-1;
    }

    void push(int element){
        if (size-top>1){
            top++;
            arr[top]=element;
        }
        else{
            cout<<"Stack overflow"<<endl;

        }

    }

    void pop(){

        if (top>0){
            top--;

        }
        else{
            cout<<"Stack undrflow"<<endl;

        }

    }

    int peek(){
        if (top>=0  && top<size){
            return arr[top];
        }
        else{
            cout<<"Stack is empty"<<endl;
            return -1;
        }


    }

    bool isEmpty(){
        if (top==-1){
            return true;

        }
        else{
            return false;
        }

    }

};

int main()
{
    /*
    // Creation of a stack
    stack<int> s;

    // Insert operation in a stack
    s.push(1);
    s.push(2);
    s.push(3);

    // Pop operation in a stack
    s.pop();

    cout << "The top element of the stack is " << s.top() << endl;

    // Checking whether stack is empty or not
    if (s.empty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }

    // Calculating the size of the stack
    cout << "The size of the stack is " << s.size() << endl;

    */


   Stack st(5);
   st.push(10);
   st.push(20);
   st.push(30);
   st.push(40);


   cout<<st.peek()<<endl;


   st.pop();
   cout<<st.peek()<<endl;
}