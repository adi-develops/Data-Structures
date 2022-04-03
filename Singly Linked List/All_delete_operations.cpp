#include <iostream>
using namespace std;

struct node
{
	int info;
	struct node *next;
};

void insert_begin(node **start, int data)
{
	struct node *new_node;
	new_node = new node;
	new_node->info = data;
	new_node->next = *start;
	*start = new_node;
}

void traverse(struct node *start)
{
	struct node *temp;
	temp = start;
	while (temp != NULL)
	{
		cout << temp->info << "\t";
		temp = temp->next;
	}
}

void delete_begin(node* &start){
    node *temp= start;
    if(start== NULL)
        cout<<"Empty list"<<endl;
    return;
    start=start->next;
    delete temp;
}

void delete_pos(node* &start, int pos){
    node *temp=start, *temp1= start;
    if(start==NULL || pos<=0){
        cout<<"Empty list or invalid location"<<endl;
        return;
    }
    if(pos==1){
        start=start->next;
        delete temp;
    }
    else if(pos>=2 && start->next!=NULL){
        for(int i=1; i<=pos-2; i++){
            temp=temp->next;
            if(temp->next==NULL){   //temp ka next check karne ka matlab ki jis element ko delete karna hai wo exist kar raha hai ki nhi
                cout<<"Location is greater than numeber of nodes."<<endl;
                return;
            }
            temp1=temp->next;
            temp->next=temp1->next;
            delete temp1;
        }
    }
    else
        cout<<"Location is greater than number of nodes."<<endl;
}


void delete_end(node* &start){
    node *temp, *temp1;
    temp1= start;
    if(start== NULL){
        cout<<"Empty list";
        return;}
    else if(start->next== NULL){
        start=NULL;
    delete temp1;
    return;}
    while(temp->next!=NULL){
        temp=temp1;
        temp1=temp1->next;
    }
    temp->next= NULL;
    delete temp1;
}

int main(){
    node *head = NULL;
	int x;
	cout << "1: Beginning, 2: Postion, 3: End" << endl;
	cin >> x;
int n;
    cout<<"Enter number of elements to be inserted: "<<endl;
	cin>>n;
	for(int i=1; i<=n; i++){
		insert_begin(&head, i);
		}
	switch (x)
	{
	case 1:
		delete_begin(head);
		break;
	case 2:
		int location;
		cout << "Enter postion: " << endl;
		cin >> location;
		delete_pos(head, location);
		break;
	case 3:
		delete_end(head);
		break;
	default:
		cout<<"Invalid"<<endl;;
		break;
	}
	traverse(head);
	return 0;
}