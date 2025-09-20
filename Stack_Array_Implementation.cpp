#include <iostream>
using namespace std;

class Stack{
    int top,capacity;
    int *arr;

    public:
        Stack(int size){
            this->capacity=size;
            top=-1;
            arr= new int[capacity];
        }

        ~Stack(){
            delete[] arr;
        }

        void push(int val){
            if(top>=capacity-1){
                cout<<"Stack Overflow"<<endl;
                return;
            }
            arr[++top]=val;
        }

        int pop(){
            if(top<0){
                cout<<"Stack Underflow"<<endl;
                return -1;
            }
            return arr[top--];
        }

        int peek(){
            if(top<0){
                cout<<"Stack Underflow"<<endl;
                return -1;
            }
            return arr[top];
        }
        
        bool isEmpty(){
            return top<0;
        }

        int size(){
            return top+1;
        }

};

int main(){
    Stack S(5);
    S.push(1);
    S.push(2);
    S.push(3);
    S.push(4);
    cout<<S.peek()<<endl;


}