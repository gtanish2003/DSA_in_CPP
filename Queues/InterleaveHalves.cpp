#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void interLeaveQueue(queue <int>& q) 
{
    stack<int> s;
    
    int n=q.size()/2;
    
    // step-1: First half of queue into stack
    for(int i=0;i<n;i++)
    {
        int val=q.front();
        q.pop();
        s.push(val);
    }
    
    // step-2: stack se firse queue me push kardo
    while(!s.empty())
    {
        int val=s.top();
        s.pop();
        q.push(val);
    }

    // step-3: first half of queue pop and queue me hi push 
    for(int i=0;i<n;i++)
    {
        int val=q.front();
        q.pop();
        q.push(val);
    }

    // step-4: Again First half of queue into stack (Repeat step-1)
    for(int i=0;i<n;i++)
    {
        int val=q.front();
        q.pop();
        s.push(val);
    }
    
    // step-5: first half of queue into stack
    while(!s.empty())
    {
        int val=s.top();
        s.pop();
        q.push(val);

        val=q.front();
        q.pop();
        q.push(val);
    }
    
}



