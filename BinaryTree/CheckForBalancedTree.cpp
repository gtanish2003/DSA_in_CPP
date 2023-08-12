#include<iostream>
#include<cmath>
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

int height(Node*root){
    //base case
    if (root==NULL){
        return 0;
    }

    int left=height(root->left);
    int right=height(root->right);

    int ans=max(left,right)+1;

    return ans;
}


//Approch-1. This approches uses height function.. So time complexity is O-(N2)...
bool isBalanced(Node*root){
    //base case
    if (root==NULL){
        return true;
    }

    //main logic
    bool left=isBalanced(root->left);
    bool right=isBalanced(root->right);
    bool diff=fabs(height(root->left)-height(root->right))<=1;
    if (left  && right &&  diff){
        return true;
    }
    return false;
}

// Lets us construct another function which does the same thing in O(N)...

pair<bool,int> isBalancedFast(Node*root){
    //base case
    if (root==NULL){
        pair<bool,int>p=make_pair(true,0);
        return p;
    }

    // main logic
    pair<bool,int>left=isBalancedFast(root->left);
    pair<bool,int>right=isBalancedFast(root->right);

    bool leftAns=left.first;
    bool rightAns=right.first;
    bool diff =fabs(left.second-right.second)<=1;

    pair<bool,int>ans;
    ans.second=max(left.second,right.second)+1;
    if (leftAns &&  rightAns  && diff)
    {
        ans.first=true;
        
    }
    else{
        ans.first=false;
    }
    

    return ans;


    
}