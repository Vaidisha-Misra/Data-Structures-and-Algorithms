#include <iostream>
using namespace std;

class Two_Stacks{
    int n;
    int *arr;
    int tos1;
    int tos2;
    public:
    Two_Stacks(int n){
        this->n=n;
        arr= new int[n];
        tos1=-1;
        tos2=n;
    }

    ~Two_Stacks(){
        delete[] arr;
    }

    void push1(int val){
        if(tos1+1>=n || tos1+1>=tos2){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        tos1++;
        arr[tos1]=val;
        cout<<"Pushed element "<<val<<" in stack 1"<<endl;
    }

    void push2(int val){
        if(tos2<=0 || tos1+1>=tos2){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        tos2--;
        arr[tos2]=val;
        cout<<"Pushed element "<<val<<" in stack 2"<<endl;
    }

    int pop1(){
        if(tos1<=-1){
            cout<<"Stack 1 is empty."<<endl;
            return -1;
        }
        int val=arr[tos1];
        tos1--;
        cout<<"Popped element "<<val<<" from stack 1"<<endl;
        return val;
    }

    int pop2(){
        if(tos2>=n){
            cout<<"Stack 2 is empty."<<endl;
            return -1;
        }
        int val=arr[tos2];
        tos2++;
        cout<<"Popped element "<<val<<" from stack 2"<<endl;
        return val;
    }


};

int main(){

    Two_Stacks S(5);

    int nop;
    cout<<"Enter number of operations you want to perform"<<endl;
    cin>> nop;
    int num;
    int val;
    cout<<"Enter 1 for pushing element in stack 1"<<endl
    << " 2 for pushing element in stack 2"<<endl
    << " 3 for poping an element from stack 1"<<endl
    << " 4 for poping an element from stack 2"<<endl;
    while(nop){
        cin>>num;
        switch(num){
            case 1:
            cin>>val;
            S.push1(val);
            break;

            case 2:
            cin>>val;
            S.push2(val);
            break;

            case 3:
            S.pop1();
            break;

            case 4:
            S.pop2();
            break;
        }
        nop--;
    }
}