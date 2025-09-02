#define MAX 10
#include <iostream>
using namespace std;

class Array{
    int arr[MAX];
    int size;

    public:

    Array(){
        size=0;
    }

    void Print(){
        cout<<"Array Elements : ";
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    void insAtEnd(int el){
        if(size<MAX){
            arr[size]=el;
            size++;
        }
        else cout<<"Array is full"<<endl;
    }

    void insAtBegin(int el){
        if(size>MAX-1){
            cout<<"Array is full"<<endl;
            return;
        }
        for(int i=size;i>0;i--){
            arr[i]=arr[i-1];
        }
        arr[0]=el;
        size++;
    }

    void insAtPos(int el,int index){
        if(size>MAX-1){
            cout<<"Array is full"<<endl;
            return;
        }
        if(index>size){
            cout<<"index out of bound"<<endl;
            return;
        }
        for(int i=size;i>index;i--){
            arr[i]=arr[i-1];
        }
        arr[index]=el;
        size++;

    }

    void insAfterElement(int el,int val){
        if(size>MAX-1){
            cout<<"Array is full"<<endl;
            return;
        }
        int i;
        for(i=0;i<size;i++){
            if(arr[i]==el) break;
        }
        if(i==size){
            cout<<"element not found"<<endl;
            return;
        }
        for(int j=size;j>i+1;j--){
            arr[j]=arr[j-1];
        }
        arr[i+1]=val;
        size++;
    }

    int deleteAtEnd(){
        if(size<1){
            cout<<"Array is Empty"<<endl;
            return -1;
        }
        size--;
        return arr[size];
    }

    int deleteAtBegin(){
        if(size<1){
            cout<<"Array is Empty"<<endl;
            return -1;
        }
        int el=arr[0];
        for(int i=1;i<size;i++){
            arr[i-1]=arr[i];
        }
        size--;
        return el;
    }

    int deleteAtPos(int pos){
        if(size<1){
            cout<<"Array is Empty"<<endl;
            return -1;
        }
        if(pos>=size){
            cout<<"index out of bound";
            return -1;
        }
        int el=arr[pos];
        for(int i=pos+1;i<size;i++){
            arr[i-1]=arr[i];
        }
        size--;
        return el;
    }

    int deleteElement(int el){
        if(size<1){
            cout<<"Array is Empty"<<endl;
            return -1;
        }
        int i;
        for(i=0;i<size;i++){
            if(arr[i]==el) break;
        }
        if(i==size){
            cout<<"element not found"<<endl;
            return -1;
        }
        for(int j=i+1;j<size;j++){
            arr[j-1]=arr[j];
        }
        size--;
        return el;
    }

    int linearSearch(int el){
        if(size<1){
            cout<<"Array is Empty"<<endl;
            return -1;
        }
        for(int i=0;i<size;i++){
            if(arr[i]==el){
                cout<<"element found"<<endl;
                return i;
            }
        }
        cout<<"element not found in array"<<endl;
        return -1;
    }

    int binarySearch(int el){
        int start=0;
        int end=size-1;
        int mid;
        while(start<=end){
            mid=(start+end)/2;
            if(arr[mid]==el){
                cout<<"element found in array"<<endl;
                return mid;
            }
            else if(arr[mid]>el) end=mid-1;
            else start=mid+1;
        }
        cout<<"element not found in array"<<endl;
        return -1;
    }
    void bubbleSort(){
        int n=size;
        int flag;
        for(int i=0;i<n-1;i++){
            flag=0;
            for(int j=0;j<n-i-1;j++){
                if(arr[j]>arr[j+1]){
                    flag=1;
                    swap(arr[j],arr[j+1]);
                }
            }
            if(flag==0) break;
        }
     }
};
int main(){
    Array a1;
    int n;
    int el;
    int ind;
    int val;
    int op;
    cin>>op;
    while(op){
        
        cin>>n;
        switch (n){
            case 1:
                cin>>el;
                a1.insAtBegin(el);
                a1.Print();
                break;
            case 2:
                cin>>el;
                a1.insAtEnd(el);
                a1.Print();
                break;
            case 3:
                a1.deleteAtBegin();
                a1.Print();
                break;
            case 4:
                a1.deleteAtEnd();
                a1.Print();
                break;
            case 5:
                a1.Print();
                break;
            case 6:
                cin>>el;
                cin>>ind;
                a1.insAtPos(el,ind);
                a1.Print();
                break;
            case 7:
                cin>>el;
                cin>>val;
                a1.insAfterElement(el,val);
                a1.Print();
                break;
            case 8:
                cin>>ind;
                a1.deleteAtPos(ind);
                a1.Print();
                break;
            case 9:
                cin>>el;
                a1.deleteElement(el);
                a1.Print();
                break;
            case 10:
                cin>>el;
                a1.linearSearch(el);
                break;
            case 11:
                cin>>el;
                a1.binarySearch(el);
                break;
            case 12:
               a1.bubbleSort();
               a1.Print();
               break;
        
        }
        op--;
    }
} 