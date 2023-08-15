#include <iostream>
#include <vector>
#include <queue>
#include<map>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

vector<int> topView(Node*root){
    map<int,int>topNode;
    queue<pair<Node*,int>>q;
    vector<int>ans;
    q.push(make_pair(root,0));
    if (root==NULL){
        return ans;
    }

    while(!q.empty()){
        pair<Node*,int>temp=q.front();
        Node*frontNode=temp.first;
        int HD=temp.second;

        //maintain one to one mapping 

        topNode[HD]=frontNode->data;
        

        if (frontNode->left){
            q.push(make_pair(frontNode->left,HD-1));
        }
        if (frontNode->right){
            q.push(make_pair(frontNode->right,HD+1));
        }

    }

    for (auto i:topNode){
        ans.push_back(i.second);

    }
    return ans;
}