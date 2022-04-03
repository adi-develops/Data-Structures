#include <iostream>
using namespace std;

struct stack{
  int arr[10];
  int top;
};

void push(stack * s, int data){
  if (s->top==9){
    cout<<"Stack is full"<<endl;
    return;
  }
  else{
    s->top++;
    s->arr[s->top]=data;
    cout<<"Top: "<<s->top<<endl;
  }
}

int pop(stack *s){
  if (s->top==-1){
    cout<<"Empty stack"<<endl;
    return -1;
  }
  int item;
  item=s->arr[s->top];
  s->top--;
  return item;
}

void display(stack *s){
  if (s->top==-1){
    cout<<"Empty stack"<<endl;
    return;
  }
  for(int i=s->top; i>-1; i--){
    cout<<s->arr[i]<<endl;
  }
}

int main() {
  stack stk;
  stk.top=-1;
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
      push(&stk, item);
      break;

    case 2:
      cout<<pop(&stk)<<endl;
      break;

    case 3:
      display(&stk);
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