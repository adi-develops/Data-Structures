#include <iostream>
using namespace std;
struct node
{
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


void reverseLinkedList(node *&start)
{
    node *p;
    node *c;
    node *n;
    if (start == NULL || start->next == NULL)
    {
        cout << "empty linked list or Linked List has only one element" << endl;
    }
    c = start;
    n = c->next;
    c->next = NULL;
    while (n != NULL)
    {
        p = c;
        c = n;
        n = n->next;
        c->next = p;
    }
    start = c;
}
int main()
{
    
}