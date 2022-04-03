#include<iostream>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};

void preOrder(node* root){
    if(root!=NULL){
        cout<<root->data<<"\t";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(node* root){
    if(root!=NULL){
        inOrder(root->left);
        cout<<root->data<<"\t";
        inOrder(root->right);
    }
}

void postOrder(node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<"\t";
    }
}

node *createNode(int info){
    node *new_node= new node;
    new_node->data= info;
    new_node->left= NULL;
    new_node->right= NULL;
    return new_node;
}

int main(){
    node *r=createNode(15);
    node *n2=createNode(24);
    node *n3=createNode(176);
    node *n4=createNode(153);
    node *n5=createNode(1212);
    node *n6=createNode(1311);

    r->left=n2;
    r->right=n3;
    n2->left=n4;
    n2->right=n5;
    n3->right=n6;

    preOrder(r);
    cout<<endl;
    inOrder(r);
    cout<<endl;
    postOrder(r);
    cout<<endl;
    return 0;
}