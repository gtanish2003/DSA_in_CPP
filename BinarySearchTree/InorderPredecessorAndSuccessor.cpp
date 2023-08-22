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

void findPRESUC(Node*root,Node*&pre,Node*&suc,int key){
    //base case
    if (root==NULL){
        return;

    }
    //if key is present at root
    if(root->data == key){
        // then max value in left subtree is predecessor
        if (root->left!=NULL){
            Node*temp=root->left;
            while(temp->right!=NULL){
                temp=temp->right;
            }
            pre=temp;
        }

        // min value in right subtree is successor
        if (root->right!=NULL){
            Node*temp=root->right;
            while(temp->left!=NULL){
                temp=temp->left;
            }
            suc=temp;
        }
        return;
    }
   //if key is smaller than root->data, then go to the left subtree
   if (root->data  > key){
    suc=root;
    findPRESUC(root->left,pre,suc,key);
   }
   else{
         pre=root;
         findPRESUC(root->right,pre,suc,key);
   }

}



///2 nd approch to find the inorder predecessor and successor

void find_p_s(Node* root,int key,Node*& p, Node*& q)
{
    // If root is null return
    if(!root)
        return ;
         
    // traverse the left subtree   
    find_p_s(root->left, key, p, q);
     
    // root data is greater than a
    if(root &&  root->data > key)
    {
         
        // q stores the node whose data is greater
        // than a and is smaller than the previously
        // stored data in *q which is successor
        if((!q) || (q) && (q)->data > root->data)
                q = root;
    }
     
    // if the root data is smaller than
    // store it in p which is predecessor
    else if(root && root->data < key)
    {
        p = root;
    }
     
    // traverse the right subtree
    find_p_s(root->right, key, p, q);
}