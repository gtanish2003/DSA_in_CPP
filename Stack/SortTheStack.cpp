#include<iostream>
#include<stack>
using namespace std;

void sortedInsert(stack<int>&stack,int num){
    if (stack.empty()  ||   (!stack.empty()  &&  stack.top()<num)){
        stack.push(num);
        return;
    }
    int n=stack.top();
    stack.pop();
    //recursion call
    sortedInsert(stack,num);

    stack.push(n);

}

void sortStack(stack<int>&stack){
    //base case
    if (stack.empty()){
        return;
    }

    int num=stack.top();
    stack.pop();

    //recursive call

    sortStack(stack);

    sortedInsert(stack,num);
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

    cout<<"Stack after sorting is:"<<endl;
    sortStack(st);
    print(st);
}