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

void MorrisTraversal(Node*root){



    // If left child is null, print the current node data. Move to
    // right child.
    while(root!=NULL){
        if (root->left==NULL) {
            cout<< root -> data <<" ";
            root=root->right;
    }
    else{
        /* Find inorder predecessor of current */
        Node*current=root->left;
        while(current->right  &&   current->right!=root){
            current = current->right ;

        }

        //temp link creation
        if (current->right == NULL){
            current->right=root;
            root=root->left;
         

        }
        else{
            //temp link remove 
            current->right=NULL;
            //print the data at present level and move to next level
            cout << root->data<<" " ;
            root=root->right;
        }

    }
}
}