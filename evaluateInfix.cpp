#include <bits/stdc++.h>
using namespace std;

int precedence(char c) {
    if (c== '^') return 3;
    if (c =='*' ||c== '/') return 2;
    if (c =='+'|| c =='-') return 1;
    return -1;
}

bool isOperator(char c) {
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}


string infixToPrefix(string infix) {
    
    reverse(infix.begin(), infix.end());

    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    stack<char> st;
    string result;

    for (char c : infix) {
        if (isalnum(c)) {
            result += c;
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else if (isOperator(c)) {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    reverse(result.begin(), result.end());
    return result;
}

int evaluatePrefix(string prefix) {
    stack<int> st;

   
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];

       if (isdigit(c)) {
            st.push(c - '0');
        }
        else if (isOperator(c)) {
            int a = st.top(); 
            st.pop();
            int b = st.top(); 
            st.pop();

            switch (c) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/': st.push(a / b); break;
                case '^': st.push(pow(a, b)); break;
            }
        }
    }
    return st.top();
}


int main() {
    string infix = "(5+3)*2-(9/3)";
    cout << "Infix Expression: "<< infix <<endl;

    string prefix = infixToPrefix(infix);
    cout << "Prefix Expression: " <<prefix<<endl;

    int result = evaluatePrefix(prefix);
    cout << "Evaluated Result: " <<result<<endl;

    return 0;
}
