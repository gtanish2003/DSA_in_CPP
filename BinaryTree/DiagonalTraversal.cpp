#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node*left;
    Node*right;

    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }

};

vector<int> diagonal(Node*root){
    vector<int>diagonalVals;
    if (root==NULL){
        return;
    }
    queue<Node*>leftQueue;
    Node* node=root;

    while(node){
        //add current node to output
        diagonalVals.push_back(node->data);
        //if left child available add it to the queue
        if (node->left){
            leftQueue.push(node->left);

        }
        //if right child available transfer the node to the right
        if (node->right){
            node=node->right;
        }
        else{
            if (!leftQueue.empty()){
                node=leftQueue.front();
                leftQueue.pop();
            }
            else{
                node=NULL;
            }
        }
    }
    return diagonalVals;
}