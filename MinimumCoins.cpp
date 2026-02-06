#include<bits/stdc++.h>
using namespace std;


vector<int> coinChange(int v){
    int arr[]={1000,500,100,50,20,10,5,2,1};
    int i=0;
    vector<int> ans;
    while(v){
        while(v>=arr[i]){
            
            v-=arr[i];
            ans.push_back(arr[i]);
        }
        i++;
    }
    return ans;
}
int main(){
    int V=49;
    auto ans=coinChange(V);
    for(auto it:ans){
        cout<<it<<" ";
    }   

}