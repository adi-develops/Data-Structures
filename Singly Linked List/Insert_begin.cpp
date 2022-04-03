#include <iostream>
using namespace std;

struct node{
	int info;
	struct node *next;
};

void traverse(node *start){
	struct node *temp;
	temp= start;
	while(temp!=NULL){
		cout<<temp->info<<"\t";
		temp=temp->next;
	}
}


void insert_begin(node **start, int data){
	node *new_node;
	new_node= new node;
	new_node->info=data;
	new_node->next=*start;
	*start=new_node;
}

int main() {
	node *head;
	head=NULL;
	int n, item;
	cout<<"Enter number of elements to be inserted: "<<endl;
	cin>>n;
	for(int i=0; i<n; i++){
		
		cout<<"Enter element "<<i+1<<":"<<endl;
		cin>>item;
		insert_begin(&head, item);
		}
	traverse(head);
    return 0;
}




// #include <iostream>
// using namespace std;

// struct node{
// 	int info;
// 	struct node *next;
// };

// void traverse(struct node *start){
// 	struct node *temp;
// 	temp= start;
// 	while(temp!=NULL){
// 		cout<<temp->info<<"\t";
// 		temp=temp->next;
// 	}
// }


// struct node *insert_begin(struct node *start, int data){
// 	struct node *new_node;
// 	new_node= new node;
// 	new_node->info=data;
// 	new_node->next=start;
// 	start=new_node;
// 	return start;
// }

// int main() {
// 	struct node *head;
// 	head=NULL;
// 	int n, item;
// 	cout<<"Enter number of elements to be inserted: "<<endl;
// 	cin>>n;
// 	for(int i=0; i<n; i++){
		
// 		cout<<"Enter element "<<i+1<<":"<<endl;
// 		cin>>item;
// 		head=insert_begin(head, item);
// 		}
// 	traverse(head);
//     return 0;
// }