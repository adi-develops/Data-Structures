#include<iostream>
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
}

void insert_begin(node **start, int data)
{
	struct node *new_node;
	new_node = new node;
	new_node->info = data;
	new_node->next = *start;
	*start = new_node;
}

void insert_pos(node **start, int data, int pos)
{
	node *new_node = new node;
	node *temp = *start;
	
	new_node->info= data;
	if (pos == 1)
	{
		new_node->next = *start;
		*start = new_node;
	}
	else if (pos >= 2 && temp != NULL)
	{
		cout<<"Hello";
		for (int i = 1; i <= pos - 2; i++)
		{
			temp = temp->next;
			if (temp == NULL)    //Temp wala check karenge ki wo exist kar raha hai ki nhi, agar location se pehle wala exist hi nhi karega to location par kaise insert karenge
			{
				cout << "Position is greater than number of nodes.";
				return;
			}
		}
		new_node->next = temp->next;
		temp->next = new_node;
		cout<<"Hello";
	}
	else
	{
		cout << "Empty list or Invalid location";
	}
}

void insert_end(node **start, int data)
{
	node *new_node;
	new_node = new node;
	new_node->info = data;
	new_node->next = NULL;
	if (*start == NULL)
		*start = new_node;
	else
	{
		node *temp = *start;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
	}
}

int main()
{
	node *head = NULL;
	int x, element;
	cout << "1: Beginning, 2: Postion, 3: End" << endl;
	cin >> x;

	switch (x)
	{
	case 1:
		cout << "Enter element: " << endl;
		cin >> element;
		insert_begin(&head, element);
		break;
	case 2:
		int location;
		cout << "Enter element: " << endl;
		cin >> element;
		cout << "Enter postion: " << endl;
		cin >> location;
		insert_pos(&head, element, location);
		break;
	case 3:
		cout << "Enter element: " << endl;
		cin >> element;
		insert_end(&head, element);
		break;
	default:
		cout<<"Invalid"<<endl;;
		break;
	}
	traverse(head);
	return 0;
}