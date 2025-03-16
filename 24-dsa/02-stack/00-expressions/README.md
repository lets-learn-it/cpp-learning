# Expressions

- **Precedence** - tells us which operators should be evaluated first
  - power operator (`^`) has highest precedence then `*` & `/` after that `+` & `-`. Then all other operators
  ```cpp
  int precedence(char c) {
    if (c=='^')                return 3;
    else if (c=='*' || c=='/') return 2;
    else if (c=='+' || c=='-') return 1;
    else                       return -1;
  }
  ```
- Type of expressions
  - Infix
  - Prefix
  - Postfix

## Infix to Postfix

```cpp
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
```