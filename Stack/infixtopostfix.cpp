#include<bits/stdc++.h>
using namespace std;

int prec(char o){
  if(o=='^')
    return 3;
  else if(o=='*' || o=='/')
    return 2;
  else if(o=='+' || o=='-')
    return 1;
  return -1;
}

void infixtoPostfix(string s){
  stack<char> st;
  string postfix;
  
  for(int i=0; i<s.length(); i++){
    char c= s[i];
  
    if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9'))
      postfix+=c;

    else if(c=='(')
      st.push(c);

    else if(c==')'){
      while(st.top()!='('){
        postfix+=st.top();
        st.pop();
      }
      st.pop();}

    else{
      while(!st.empty() && prec(c)<=prec(st.top())){
        postfix+=st.top();
        st.pop();
      }
      st.push(c);
    }
  }

while(!st.empty()){
  postfix+=st.top();
  st.pop();
}

cout<<"Postfix expression: "<<postfix;
}

int main(){
  string str="a+(b*c-(d/e^f)*g)*h";
  infixtoPostfix(str);
  return 0;
}