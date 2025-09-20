
#include <iostream>
using namespace std;

class myStack {
    int *arr;
    int capacity;
    int top;        

    public:

    myStack(int cap) {
        capacity = cap;
        arr = new int[capacity];
        top = -1;
    }

    void push(int x) {
        if (top >= capacity - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (top<0) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    
    int peek() {
        if (top<0) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top<0;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    int size(){
        return top+1;
    }
};

int main() {
    myStack st(4);

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << "Popped: " << st.pop() << "\n";

    cout << "Top element: " << st.peek() << "\n";

    cout << "Is stack empty: " << (st.isEmpty() ? "Yes" : "No") << "\n";

    cout << "Is stack full: " << (st.isFull() ? "Yes" : "No") << "\n";

    return 0;
}