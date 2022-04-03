#include <iostream>
using namespace std;

struct node{
	int info;
	struct node *next;
};

void traverse(struct node *start)
{
	struct node *temp;
	temp = start;
	while (temp != NULL)
	{
		cout << temp->info << "\t";
		temp = temp->next;
	}
    cout<<endl;
}

void insert_begin(node **start, int data){
	node *new_node;
	new_node= new node;
	new_node->info=data;
	new_node->next=*start;
	*start=new_node;
}

int search(node **start, int data){
    node *temp= *start;
    int loc=0;
    if(temp==NULL){
        cout<<"Empty list"<<endl;
        return -1;
    }
    while(temp!=NULL){
        loc++;
        if(temp->info==data)
            return loc;
        temp=temp->next;
    }
    return -1;
}

int main(){
    node *head;
	head=NULL;
    int n;
    cout<<"Enter number of elements to be inserted: "<<endl;
	cin>>n;
	for(int i=1; i<=n; i++){
		insert_begin(&head, i*2);
		}
    traverse(head);
    cout<<search(&head, 8);
    return 0;
}