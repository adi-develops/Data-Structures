#include<iostream>
using namespace std;

struct node{
    int info;
    node *next;
};

struct queue{
    node *f;
    node *r;
};

void enqueue(queue *q, int item){
    node *new_node=new node;
    new_node->info= item;
    new_node->next =NULL;
    if(q->f==NULL || q->r==NULL){
        q->r=q->f=new_node;
    }
    else{
        (q->r)->next=new_node;
        q->r=new_node;
    }
}

int dequeue(queue *q){
    node *temp=q->f;
    if(q->f==NULL || q->r==NULL){
        cout<<"Queue empty";
        return -1;
    }
    int item=(q->f)->info;
    if(q->f==q->r){
        q->f=q->r=NULL;
    }
    else{
        q->f=(q->f)->next;
    }
    delete temp;
    return item;
}

void front(queue q){
    if(q.f==NULL || q.r==NULL){
        cout<<"Empty queue"<<endl;
        return;}
    cout<<(q.f)->info<<endl;
}

void display(queue q){
    if(q.f==NULL || q.r==NULL){
        cout<<"Empty queue"<<endl;
        return;
    }
    while(q.f!=NULL){
        cout<<q.f->info<<"\t";
        q.f=q.f->next;
    }
    cout<<endl;
}

int main(){
    queue q;
    q.f=q.r=NULL;
    int n;

    bool a= true;
    while (a==true){
    cout<<"****Queue Menu****"<<endl;
    cout<<"1. Insert"<<endl<<"2. Delete"<<endl<<"3. Display front"<<endl<<"4. Display queue"<<endl<<"5. Exit"<<endl;
    cout<<"Enter your choice(1-5): ";
    cin>>n;

    switch(n){
        case 1:
        int item;
        cout<<"Enter the element to insert: ";
        cin>>item;
        enqueue(&q, item);
        break;

        case 2:
        cout<<"Item deleted: "<<dequeue(&q)<<endl;
        break;

        case 3:
        front(q);
        break;

        case 4:
            display(q);
            break;

        case 5:
        a=false;
        cout<<"Program exited"<<endl;
        break;

        default:
        cout<<"Wrong input."<<endl;
    }
    }

    return 0;
}