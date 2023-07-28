#include<iostream>
#include<stack>
using namespace std;


void insertAtBottom(stack<int>&s,int num){
    // base case
    if (s.empty()){
        s.push(num);
        return;
    }

    int element=s.top();
    s.pop();

    // Recursive call
    insertAtBottom(s,num);
    s.push(element);



}

void reverseStack(stack<int>&stack){
    //base case
    if (stack.empty()){
        return;
    }

    int num=stack.top();
    stack.pop();


    //recursive call
    reverseStack(stack);

    insertAtBottom(stack,num);
}

void print(stack<int>stack){
    while(!stack.empty()){
        cout<<stack.top()<<" ";
        stack.pop();
    }
    cout<<endl;


}

int main(){
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
      cout<<"Stack originally was:"<<endl;
      print(st);

      reverseStack(st);
      cout<<"Stack after reversing :"<<endl;
      print(st);

}