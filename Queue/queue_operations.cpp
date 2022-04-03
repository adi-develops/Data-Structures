#include <iostream>
using namespace std;

struct queue
{
    int size, f, r;
    int *arr;
};

void createqueue(queue *qu, int sz)
{
    qu->f = qu->r = -1;
    qu->size = sz;
    qu->arr = new int[sz];
}

void enqueue(queue *q, int item)
{
    if (q->f == -1 || q->r == -1)
    {
        q->f = q->r = 0;
    }
    else if (q->r == q->size - 1)
    {
        if (q->f == 0)
        {
            cout << "Queue overflow"<<endl;
            return;
        }
        int temp = q->f, i = 0;
        while (temp <= q->r)
        {
            q->arr[i] = q->arr[temp];
            i++;
            temp++;
        }
        q->r = q->r - q->f + 1;
        q->f = 0;
    }
    else
    {
        q->r++;
    }
    q->arr[q->r] = item;
}

int dequeue(queue *q)
{
    if (q->f == -1 || q->r == -1)
    {
        cout << "Queue empty";
        return -1;
    }
    int item = q->arr[q->f];
    if (q->f == q->r)
    {
        q->f = q->r = -1;
    }

    else
    {
        q->f++;
    }
    return item;
}

void traverse(queue q)
{
    if(q.f == -1 || q.r==-1){
        cout<<"Empty queue"<<endl;
        return;
    }
    for (int i = q.f; i <= q.r; i++)
        cout << q.arr[i] << "\t";
    cout<<endl;
}

void front(queue q){
    if(q.f == -1 || q.r==-1){
        cout<<"Empty queue"<<endl;
        return;
    }
    cout<<q.arr[q.f]<<endl;
}

int main()
{
    queue line;
    int s;
    cout<<"Enter size: "<<endl;
    cin >> s;
    createqueue(&line, s);
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
        enqueue(&line, item);
        break;

        case 2:
        cout<<"Item deleted: "<<dequeue(&line)<<endl;
        break;

        case 3:
            front(line);
            break;

        case 4:
            traverse(line);
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