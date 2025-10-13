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

        Node(int data){
            this->data=data;
            this->next=NULL;
        }
};

class LinkedList{
    Node *head;
    public:
        LinkedList(){
            head=NULL;
        }

        void Print(){
            Node *temp=head;
            while(temp){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
        
        void InsertAtHead(int val){
            Node *temp=new Node(val);
            temp->next=head;
            head=temp;
        }

        void InsertAtEnd(int val){
            Node *temp= new Node(val);
            if(head==NULL){
                head=temp;
                return;
            }
            Node *end=head;
            while(end->next){
                end=end->next;
            }
            end->next=temp;
        }

        void InsertAtPosN(int val,int pos){
            Node *temp=new Node(val);
            if(pos==1){
                temp->next=head;
                head=temp;
                return;
            }
            Node *prev=head;
            for(int i=0;i<pos-2 && prev!=NULL;i++){
                prev=prev->next;
            }
            if(prev==NULL) {
                cout<<"Index out of bounds."<<endl;
                delete temp;
                return;
            }
            temp->next=prev->next;
            prev->next=temp;
            
        }

        int DeleteAtHead(){
            if(head==NULL){
                cout<<"The list is empty"<<endl;
                return -1;
            }

            Node *temp=head;
            head=temp->next;
            int val=temp->data;
            delete temp;
            return val;
        }

        int DeleteAtEnd(){
            if(head==NULL){
                cout<<"The list is empty"<<endl;
                return -1;
            }

            if(head->next==NULL){
                Node *temp=head;
                head=temp->next;
                int val=temp->data;
                delete temp;
                return val;
            }

            Node *prev=head;
            while(prev->next->next){
                prev=prev->next;
            }
            Node *temp=prev->next;
            int val=temp->data;
            prev->next=NULL;
            delete temp;
            return val;

        }

        int DeleteAtPosN(int pos){
            if(head==NULL){
                cout<<"The list is empty"<<endl;
                return -1;
            }

            if(pos==1){
                Node *temp=head;
                head=head->next;
                int val=temp->data;
                delete temp;
                return val;
            }
            Node *prev=head;
            for(int i=0;i<pos-2;i++){
                prev=prev->next;
            }
            Node *temp=prev->next;
            int val=temp->data;
            prev->next=temp->next;
            delete temp;
            return val;
        }
        
        void Reverse(){
            if(head==NULL || head->next==NULL){
                return;
            }
            Node *prev=NULL,*current=head,*next;

            while(current){
                next=current->next;
                current->next=prev;
                prev=current;
                current=next;
            }
            head=prev;

        }

};

int main(){
    LinkedList L1;
    L1.InsertAtHead(1);
    L1.Print();
    L1.InsertAtHead(2);
    L1.Print();
    L1.DeleteAtHead();
    L1.Print();
    L1.InsertAtEnd(2);
    L1.Print();
    L1.InsertAtPosN(3,2);
    L1.Print();
    L1.Reverse();
    L1.Print();
    L1.DeleteAtPosN(2);
    L1.Print();
}
