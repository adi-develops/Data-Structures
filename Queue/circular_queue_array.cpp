#include <iostream>
using namespace std;

struct cqueue
{
    int size, f, r;
    int *arr;
};

void createqueue(cqueue *qu, int sz)
{
    qu->f = qu->r = -1;
    qu->size = sz;
    qu->arr = new int[sz];
}

void traverse(cqueue q){
    if(q.f == -1 || q.r==-1){
        cout<<"Empty queue"<<endl;
        return;
    }

    else if(q.f <= q.r){
        for(int i=q.f; i<=q.r; i++){
            cout<<q.arr[i]<<"\t";
        }
        
        cout<<endl;
    }

    else{
        for(int i=q.f; i<=q.size-1; i++)
            cout<<q.arr[i]<<"\t";

        for(int i=0; i<=q.r; i++)
            cout<<q.arr[i]<<"\t";
        cout<<endl;
    }
}

void enqueue(cqueue *q, int item){
    if(q->f==-1 || q->r==-1){
        q->f=q->r=0;
    }
    else if(q->r==q->size-1){
        if(q->f==0){
            cout<<"Queue overflow"<<endl;
            return;
        }
        q->r=0;
    }
    else if(q->r==q->f-1){
        cout<<"Queue overflow"<<endl;
        return;
    }
    else{
        q->r++;
    }
    q->arr[q->r]=item;
}

int dequeue(cqueue *q){
    if(q->f == -1 || q->r== -1){
        cout<<"Queue empty"<<endl;
        return -1;
    }
    int item = q->arr[q->f];

    if(q->f==q->r){
        q->f=q->r=-1;
    }
    else if(q->f==q->size-1){
        q->f=0;
    }
    else
        q->f++;
    return item;
}

void front(cqueue q){
    if(q.f == -1 || q.r==-1){
        cout<<"Empty queue"<<endl;
        return;
    }
    cout<<q.arr[q.f]<<endl;
}

int main(){
    cqueue q;
    int s;
    cout<<"Enter size: "<<endl;
    cin >> s;
    createqueue(&q, s);
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
            traverse(q);
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