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

int searchMiddle(node *&start)
{
    node *p1;
    node *p2;
    int location = 0;
    p1 = start;
    p2 = start;
    while (p2 != NULL && p2->next != NULL)
    {
        location++;
        p1 = p1->next;
        p2 = p2->next;
        p2 = p2->next;
    }
    return location;
}
int main()
{
    node *head = NULL;
    int n;
    cout<<"Enter number of elements to be inserted: "<<endl;
	cin>>n;
	for(int i=1; i<=n; i++){
		insert_begin(&head, i);
		}
    traverse(head);
    cout << "Middle Position: ";
    cout << searchMiddle(head);
    return 0;
}
