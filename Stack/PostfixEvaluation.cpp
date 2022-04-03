#include<bits/stdc++.h>
using namespace std;

void postfixtoInfix(string s){
  stack<int> st;
  int o1, o2;
  
  for(int i=0; i<s.length(); i++){
    char c= s[i];

    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^'){
      o2=st.top();
      st.pop();
      o1=st.top();
      st.pop();

      switch (c)
            {
            case '+': st.push(o1 + o2); break;
            case '-': st.push(o1 - o2); break;
            case '*': st.push(o1 * o2); break;
            case '/': st.push(o1 / o2); break;
            case '^': st.push(pow(o1, o2)); break;
            }
    }

    else if(c>='0' && c<='9'){
        st.push(c-'0');
    }

}

cout<<"Answer: "<<st.top();
}

int main(){
    string str;
    cin>>str;
    postfixtoInfix(str);
    return 0;
}