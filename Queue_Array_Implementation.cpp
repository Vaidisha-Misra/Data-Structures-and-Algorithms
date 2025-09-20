#include <iostream>
using namespace std;

class Queue{
    int *arr;
    int front,rear,capacity;
    public:
    Queue(int cap){
        arr= new int[cap];
        capacity=cap;
        front=rear=-1;
    }

    ~Queue(){
        delete[] arr;
    }

    void Enqueue(int val){
        if((rear+1)%capacity==front){
            cout<<"Queue is full"<<endl;
            return;
        }
        if(rear==-1 && front==-1){
            rear=front=0;
        }
        else{
            rear=(rear+1)%capacity;
        }
        arr[rear]=val;
    }

    int Dequeue(){
        if(rear==-1 && front==-1){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        int val=arr[front];
        if(rear==front){
            rear=front=-1;
        }
        else{
            front=(front+1)%capacity;
        }
        return val;
    }
    
    bool isEmpty(){
        return (rear==-1 && front==-1);
    }

    bool isFull(){
        return (rear+1)%capacity==front;
    }
};

int main(){
    Queue Q(5);
    Q.Dequeue();
    Q.Enqueue(1);
    cout<<Q.isEmpty()<<endl;
    cout<<Q.isFull()<<endl;
    Q.Enqueue(1);
    Q.Enqueue(1);
    Q.Enqueue(1);
    Q.Enqueue(1);
    Q.Enqueue(1);
    cout<<Q.isFull()<<endl;
    Q.Dequeue();
    cout<<Q.isFull()<<endl;
}