#include <iostream>
using namespace std;

class Node{
    public:
    int power;
    int coeff;
    Node *next;

    Node(){
        next=NULL;
    }
    
    Node(int p,int c){
        power=p;
        coeff=c;
        next=NULL;
    }
};

void Traversal(Node *head){
    if(head==NULL) return;
    while(head){
        cout<<head->coeff<<"x"<<head->power<<" +";
        head=head->next;
    }
    cout<<endl;
}


Node* Add(Node *p1,Node *p2){
        if(p1==NULL) return p2;
        else if(p2==NULL) return p1;

        Node *dummyNode=new Node(-1,-1);
        Node *temp=dummyNode;

        while(p1 && p2){
            Node *newNode=new Node();
            if(p1->power==p2->power){
                newNode->power=p1->power;
                newNode->coeff=p1->coeff+p2->coeff;
                temp->next=newNode;
                temp=newNode;
                p1=p1->next;
                p2=p2->next;
            }

            else if(p1->power>p2->power){
                newNode->power=p1->power;
                newNode->coeff=p1->coeff;
                temp->next=newNode;
                temp=newNode;
                p1=p1->next;
            }
            else{
                newNode->power=p2->power;
                newNode->coeff=p2->coeff;
                temp->next=newNode;
                temp=newNode;
                p2=p2->next;
            }
        }

        while(p1){
            temp->next=p1;
        }

        while(p2){
            temp->next=p2;
        }
        return dummyNode->next;

    }

int main(){
    Node *poly1;
    Node *temp=new Node(3,4);
    poly1=temp;
    temp->next=new Node(2,10);
    temp=temp->next;
    temp->next= new Node(1,9);
    temp=temp->next;
    temp->next=new Node(0,100);

    Traversal(poly1);

    Node *poly2;
    Node *temp2=new Node(2,200);
    poly2=temp2;
    temp2->next=new Node(0,1);

    Traversal(poly2);

    Node *polyadd=Add(poly1,poly2);
    Traversal(polyadd);
    
    
}