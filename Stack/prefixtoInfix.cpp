#include<bits/stdc++.h>
using namespace std;

void prefixtoInfix(string s){
  reverse(s.begin(), s.end());
  stack<string> st;
  string o1, o2;
  
  for(int i=0; i<s.length(); i++){
    char c= s[i];

    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^'){
      o1=st.top();
      st.pop();
      o2=st.top();
      st.pop();

      st.push("("+o1+c+o2+")");
    }

    else{
        st.push(string (1,c));
    }

}

cout<<"Infix expression: "<<st.top();
}

int main(){
    string str;
    cin>>str;
    prefixtoInfix(str);
    return 0;
}