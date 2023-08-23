#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};


int minVal(Node*root){
    Node*temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp->data;
}


Node* deletionFromBST(Node*root,int val){
     // Base case
    if(root==NULL){
        return root;
    }
    if (root->data==val){

        //0 child
        if (root->left ==NULL  && root->right==NULL){
            delete root;
            return NULL;
        }

        //1 child
        ///sub case -1   ..left child
        if (root->left!=NULL  &&  root->right==NULL){
            Node*temp=root->left;
            delete root;
            return temp;
        }



        ///sub case -2  ..right child
         if (root->right!=NULL  &&   root->left==NULL){
            Node*temp=root->right;
            delete root;
            return temp;

         }


        //2 children

        if (root->left!=NULL   &&   root->right!=NULL){
            int mini=minVal(root->right) ;
            root->data=mini;
            root->right=deletionFromBST(root->right,mini);
            return root;
        }





    }

    else if(root->data  >   val){
        //left part me jao
        root->left=deletionFromBST(root->left,val);
        return root;
    }   
    else{
        //right part me jao
        root->right=deletionFromBST(root->right,val);
        return root;
    }
    
}