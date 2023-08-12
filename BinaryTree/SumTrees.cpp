#include<iostream>
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


pair<bool,int> isSum(Node*root){
    //base case
    if (root==NULL ){
        pair<bool,int>p=make_pair(true,0);
        return p;
    }

    if (root->left==NULL && root->right==NULL){
        pair<bool,int>p=make_pair(true,root->data);
        return p;
    }

    //recursive case
    pair<bool,int>leftAns=isSum(root->left);
    pair<bool,int>rightAns=isSum(root->right);


    bool  left=leftAns.first;
    bool right=rightAns.first;

    bool condition=root->data==leftAns.second+rightAns.second;

    pair<bool,int>ans;

    if (left  &&  right   && condition ){
        ans.first=true;
        ans.second=root->data+leftAns.second+rightAns.second;

    }
    else{
        ans.first=false;
        
    }
    return ans;


}