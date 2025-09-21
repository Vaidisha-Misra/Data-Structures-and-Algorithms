#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;

    
        Node(){
            this->data=-1;
            this->next=NULL;
        }

        Node(int val){
            this->data=val;
            this->next=NULL;
        }
};

class Stack{
    Node *head;

    public:
        Stack(){
            head=NULL;
        }

        void push(int val){
            Node *temp=new Node(val);
            temp->next=head;
            head=temp;
        }

        int pop(){
            if(head==NULL){
                cout<<"Stack Underflow"<<endl;
                return -1;
            }
            Node *temp=head;
            int val=temp->data;
            head=head->next;
            delete temp;
            return val;
        }

        int peek(){
            if(head==NULL){
                cout<<"Stack Underflow"<<endl;
                return -1;
            }
            return head->data;
        }

        bool IsEmpty(){
            return head==NULL;
        }

};

int main(){
    Stack st;
    cout<<st.IsEmpty()<<endl;
    st.push(2);
    st.push(100);
    cout<<st.peek()<<endl;
    cout<<st.pop()<<endl;
    cout<<st.peek()<<endl;
}