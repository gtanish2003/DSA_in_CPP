#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*left;
    Node*right;

    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
    

  
};


  Node* buildTree(Node*root){
        cout<<"Enter the data:"<<endl;
        int data;
        cin>>data;
        root=new Node(data);
        if (data==-1){
            return NULL;
        }

        cout<<"Enter the data for inserting in left:"<<endl;
        root->left=buildTree(root->left);
        cout<<"Enter the data for inserting in right:"<<endl;
        root->right=buildTree(root->right);
    }


int main(){
    Node* root=NULL;
    root=buildTree(root);
}