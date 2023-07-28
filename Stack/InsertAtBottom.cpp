#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int>&mystack,int x){
    //Base case
    if (mystack.empty()){
        mystack.push(x);
        return;
    }
    int num=mystack.top();
    mystack.pop();

    //recursion
    solve(mystack,x);

    mystack.push(num);

}

stack<int>pushAtBottom(stack<int>&mystack,int x){
    solve(mystack,x);
    return mystack;
}

void print(stack<int>stack){
    while(!stack.empty()){
        cout<<stack.top()<<" ";
        stack.pop();
    }
    cout<<endl;


    }


int main(){
    stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    print(s);
    
    pushAtBottom(s,20);
    print(s);
 

}