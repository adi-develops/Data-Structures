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
        cout<<temp->info<<"\t";
        temp=temp->next;
    }
}

void insert_begin(node **start, node **end, int data){
    node *new_node= new node;
    new_node->info= data;
    new_node->next= *start;
    new_node->prev= NULL;
    if (*start==NULL){
        *start=new_node;
        *end=new_node;
    }
    else{
        (*start)->prev=new_node;
        *start= new_node;
    }
}

void insert_end(node *&start, node *&end, int data){
    node *new_node= new node;
    new_node->info=data;
    new_node->next= NULL;
    if(start==NULL || end==NULL){
        new_node->prev=NULL;
        start=new_node;
        end= new_node;
    }
    else{
        new_node->prev=end;
        end->next=new_node;
        end=new_node;
    }
}

void insert_loc(node *&start, node *&end, int data, int loc){
    node *new_node= new node;
    node *temp=start;
    new_node->info=data;
    if(loc==1){
        new_node->prev=NULL;
        new_node->next=start;
        if(start==NULL){
            end=new_node;
        }
        else{
            start->prev=new_node;
            start=new_node;
        }
    }
    else if(loc>=2 && temp!=NULL){
        for(int i=1; i<=loc-2; i++){
            temp=temp->next;
            if(temp==NULL){  //if Loc is greater than number of nodes+1
                cout<<"List smaller than location.";
                return;
            }
        }
        new_node->next=temp->next;
        new_node->prev=temp;
        if(temp->next!=NULL)
            temp->next->prev=new_node;    // only when LOC is not a last node
        else
            end=new_node;
        temp->next=new_node;
    }
    else
        cout<<"Invalid location."; //when location<1
}

int main(){
    node *start, *end;
    start=NULL;
    end=NULL;
    for(int i=6, j=112; i<11; i++, j++){
        insert_begin(&start, &end,i);
        insert_end(start, end, j);
    }

    insert_loc(start, end, 999, 11);
    traverse_start(start);
    cout<<endl<<end->info;
    return 0;
}