#include<iostream>
#include<queue>
#include<stack>
using namespace std;

queue<int>reverseK(queue<int>&q,int k){
    //step-1.first pop k elements from queue and put into stack
    stack<int>s;
    for(int i=0;i<k;i++){
        int val=q.front();
        q.pop();
        s.push(val);
    }

    //step-2. fetch from stack and push into queue
    while(!s.empty()){
        int val=s.top();
        s.pop();
        q.push(val);

    }

    //step-3.fetch first (n-k) elements from queue and push_back them
    int t=q.size()-k;
    while(t--){
        int val=q.front();
        q.pop();
        q.push(val); 
    }
    return q;
}