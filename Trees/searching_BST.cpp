#include<iostream>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};

node *createNode(int info){
    node *new_node= new node;
    new_node->data= info;
    new_node->left= NULL;
    new_node->right= NULL;
    return new_node;
}

node* search_recur(node *root, int key){
    if(root==NULL){
        return NULL;
    }
    if(key==root->data){
        return root;
    }
    else if(key<root->data){
        return search_recur(root->left, key);
    }
    else{
        return search_recur(root->right, key);
    }
}

node* search(node* root, int key){
    while(root!=NULL){
        if(key==root->data){
            return root;
        }
        else if(key<root->data){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return NULL;
}

void preOrder(node* root){
    if(root!=NULL){
        cout<<root->data<<"\t";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main(){
    node *root=NULL;    
    preOrder(root);
    return 0;
}