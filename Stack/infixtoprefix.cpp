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

void infixtoPrefix(string s){
  reverse(s.begin(), s.end());
  stack<char> st;
  string prefix;
  
  for(int i=0; i<s.length(); i++){
    char c= s[i];

    if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9'))
      prefix+=c;

    else if(c==')')
      st.push(c);

    else if(c=='('){
      while(st.top()!=')'){
        prefix+=st.top();
        st.pop();
      }
      st.pop();}

    else{
      while(!st.empty() && prec(c)<prec(st.top())){
        prefix+=st.top();
        st.pop();
      }
      st.push(c);
    }
  }

while(!st.empty()){
  prefix+=st.top();
  st.pop();
}
reverse(prefix.begin(), prefix.end());
cout<<endl<<"Prefix expression: "<<prefix;
}

int main(){
  string str;
  cout<<endl;
  cin>>str;
  infixtoPrefix(str);
  return 0;
}