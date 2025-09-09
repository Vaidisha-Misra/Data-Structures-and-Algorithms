#include <iostream>
#include <vector>
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

void Merge(int arr[],int start,int mid,int end){
    vector <int> v;
    int p=start;
    int q=mid+1;
    while(p<=mid && q<=end){
        if(arr[p]<=arr[q]){
            v.push_back(arr[p]);
            p++;
        }
        else{
            v.push_back(arr[q]);
            q++;
        }
    }
    while(p<=mid){
        v.push_back(arr[p]);
        p++;
    }
    while(q<=end){
        v.push_back(arr[q]);
        q++;
    }
    for(int i=0;i<v.size();i++){
        arr[start+i]=v[i];
    }
}

void MergeSort(int arr[],int start,int end){
    if(start>=end) return;
    int mid=(start+end)/2;
    MergeSort(arr,start,mid);
    MergeSort(arr,mid+1,end);
    Merge(arr,start,mid,end);
}


int main(){
    int arr[]={2,7,1,3,90,10,0};
    Print(arr,7);
    MergeSort(arr,0,6);
    Print(arr,7);
    
}