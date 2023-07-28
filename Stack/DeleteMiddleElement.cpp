#include<iostream>
#include<stack>
using namespace std;


void solve(stack<int>&s,int count,int size){
    //BASE CASE
    if (count==size/2){
        s.pop();
        return;
    }

    int num=s.top();
    s.pop();

    //RECURSIVE CALL
    solve(s,count+1,size);
    s.push(num);

}
void deleteMiddle(stack<int>&s,int n){
    int count=0;
    solve(s,count,n);
}

int main(){
    stack<int>stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    cout<<stack.top();

    deleteMiddle(stack,5);


    cout<<stack.size();


}