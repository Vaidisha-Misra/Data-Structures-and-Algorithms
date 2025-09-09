#include <iostream>
using namespace std;
void Print(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void bubbleSort(int arr[],int size){
    bool swapped;
    for(int i=0;i<size;i++){
        swapped=false;
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                swapped=true;
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
        if(swapped==false) break;
    }
}

void SelectionSort(int arr[],int size){
    for(int i=0;i<size-1;i++){
        int small=i;
        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[small]){
                small=j;
            }
            swap(arr[i],arr[small]);
        }

    }
}
int main(){
    int arr[]={2,7,1,3,90,10,0};
    Print(arr,7);
    SelectionSort(arr,7);
    Print(arr,7);
    
}