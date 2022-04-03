#include<iostream>
using namespace std;

struct node{
    node *prev;
    int info;
    node *next;
};

void traverse_start(node *start){
    node *temp= start;
    while(temp!=NULL){
        cout<<temp->info;
        temp=temp->next;
    }
}

void traverse_end(node *end){
    node *temp=end;
    while(temp!=NULL){
        cout<<temp->info;
        temp=temp->prev;
    }
}

int main(){
    node *start, *end;
    start, end=NULL;
    return 0;
}