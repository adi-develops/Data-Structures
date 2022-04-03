#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node *createNode(int info)
{
    node *new_node = new node;
    new_node->data = info;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void preOrder(node *root)
{
    if (root != NULL)
    {
        cout << root->data << "\t";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->data << "\t";
        inOrder(root->right);
    }
}

//Insert a node using recusion

// Node* insert(Node* root, int Key) {
//     // Your code here
//     if (root==NULL){
//         return new Node(Key);
//     }
//     if(root->data>Key){
//         root->left=insert(root->left, Key);
//     }
//     else if(root->data<Key){
//         root->right=insert(root->right, Key);
//     }
//     return root;
// }

node *insert(node *root, int key)
{
    node *parent = NULL, *temp = root;
    while (temp != NULL)
    {
        parent = temp;
        if (temp->data == key)
        {
            cout << "Item already present." << endl;
            return NULL;
        }
        else if (key < temp->data)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    node *new_node = createNode(key);

    if (root == NULL)
    {
        return new_node;
    }
    if (key < parent->data)
    {
        parent->left = new_node;
    }
    else
    {
        parent->right = new_node;
    }
    return NULL;
}

node *inOrderPredecessor(node* root){
    root = root->left;
    while (root->right!=NULL)
    {
        root = root->right;
    }
    return root;
}

node *deleteNode(node *root, int key){
    node *temp;
    if(root == NULL){
        return NULL;
    }

    //Searching
    if(key<root->data){
        root->left = deleteNode(root->left, key);
    }
    else if(key>root->data){
        root->right= deleteNode(root->right, key);
    }

    else{
        //Leaf node case
        if(root->left==NULL && root->right==NULL){
            delete root;               
            return NULL;
        }
        //One child case
        else if(root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }

        else if(root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        //Two child case
        else
        {
            temp = inOrderPredecessor(root);
            root->data = temp->data;
            root->left = deleteNode(root->left, temp->data);
        }
    }
    return root;
}


int main(){
    
    node *root = NULL;
    root = insert(root, 45);
    insert(root, 453);
    insert(root, 4);
    insert(root, 4455);
    insert(root, 65);
    insert(root, 895);
    insert(root, 11);
    insert(root, 15);
    insert(root, 632);
    inOrder(root);
    deleteNode(root, 15);
    cout << endl;
    inOrder(root);
    deleteNode(root, 4);
    cout << endl;
    inOrder(root);
    return 0;    
}