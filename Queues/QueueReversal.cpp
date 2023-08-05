#include<iostream>
#include<queue>
#include<stack>
using namespace std;

queue<int> rev(queue<int>&q){
    stack<int>s;
    while(!q.empty()){
        int element=q.front();
        q.pop();
        s.push(element);
    }

    while(!s.empty()){
        int element=s.top();
        s.pop();
        q.push(element);
    }

    return q;
}

void display(queue<int>q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

int main(){
    queue<int>q1;
    q1.push(10);
    q1.push(20);
    q1.push(30);
    q1.push(40);
    q1.push(50);
    
    cout<<"Queue before reversal is :"<<endl;
    display(q1);

    queue<int>ans=rev(q1);
     cout<<"Queue after reversal is :"<<endl;
    display(q1);


}