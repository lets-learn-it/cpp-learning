#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int precedence(char c) {
  if (c=='^')                return 3;
  else if (c=='*' || c=='/') return 2;
  else if (c=='+' || c=='-') return 1;
  else                       return -1;
}

bool isOperand(char c) {
  return (c>='a' && c<='z') || (c>='A' && c<='Z');
}

string infixToPostfix(string s) {
  stack<char> st;
  string result = "";

  for (int i=0; i<s.size(); i++) {
    if (isOperand(s[i])) {
      result += s[i];
    } else if (s[i] == '(') {
      st.push(s[i]);
    } else if (s[i] == ')') {
      while(st.top() != '(') {
        result += st.top();
        st.pop();
      }
      st.pop();
    } else {
      while(!st.empty() && precedence(s[i]) <= precedence(st.top())) {
        result += st.top();
        st.pop();
      }
      st.push(s[i]);
    }
  }

  while(!st.empty()) {
    result += st.top();
    st.pop();
  }

  return result;
}

int main(int argc, char const *argv[])
{
  vector<string> s = {"a+b-c*(d^e-f)-g", "(p+q)*(m-n)"};

  for (int i=0; i<s.size(); i++)
    cout << s[i] << ": " << infixToPostfix(s[i]) << endl;
  return 0;
}
