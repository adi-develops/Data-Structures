#include<iostream>
using namespace std;

struct node{
  int info;
  node *next;
};

void push(node *&start, int item){
  node *new_node=new node;
  if(new_node==NULL){
    cout<<"Unable to allocate memory!"<<endl; 
    return;
  }
  new_node->info=item;
  new_node->next=start;
  start=new_node;
}

int pop(node *&start){
  node *temp=start;
  if(start==NULL){
    cout<<"Empty stack!"<<endl;
    return -1;
  }
  int item=start->info;
  start=start->next;
  return item;
}

void display(node *start){
  if(start==NULL){
    cout<<"Empty stack!"<<endl;
    return;
}
  while(start!=NULL){
    cout<<start->info<<endl;
    start=start->next;
  }
}

int main(){
  node *top=NULL;
  int n;
  bool a= true;
  while (a==true){
  cout<<"****Stack Menu****"<<endl;
  cout<<"1. Push"<<endl<<"2. Pop"<<endl<<"3. Display"<<endl<<"4. Exit"<<endl;
  cout<<"Enter your choice(1-4): ";
  cin>>n;

  switch(n){
    case 1:
      int item;
      cout<<"Enter the element to push: ";
      cin>>item;
      push(top, item);
      break;

    case 2:
      cout<<"Item popped: "<<pop(top)<<endl;
      break;

    case 3:
      display(top);
      break;

    case 4:
      a=false;
      cout<<"Program exited"<<endl;
      break;

    default:
      cout<<"Wrong input."<<endl;
  }
  }
  return 0;
}