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

class Queue{
    Node *front,*rear;
    public:
        Queue(){
            front=rear=NULL;
        }

        void Enqueue(int val){
            Node *temp= new Node(val);
            if(front==NULL){
                front=rear=temp;
                return;
            }
            rear->next=temp;
            rear=temp;
        }

        int Dequeue(){
            if(front==NULL){
                cout<<"Queue is empty"<<endl;
                return -1;
            }
            Node *temp=front;
            int val=temp->data;
            if(front==rear){
                front=rear=NULL;
            }
            else{
                front=front->next;
            }
            delete temp;
            return val;

        }
};

int main(){
    Queue Q;
    Q.Dequeue();
    Q.Enqueue(1);
    Q.Enqueue(2);
    cout<<Q.Dequeue()<<endl;
}