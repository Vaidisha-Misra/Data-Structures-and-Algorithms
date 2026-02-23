#include <bits/stdc++.h>
using namespace std;

void generateBinaryStrings(vector <string> &ans,int n,int i,int prev,string s){
    if(i==n){
        ans.push_back(s);
        return;
    }
    if(prev==0){
        s+='0';
        generateBinaryStrings(ans,n,i+1,0,s);
        s.pop_back();

        s+='1';
        generateBinaryStrings(ans,n,i+1,1,s);
        s.pop_back();
    }
    else {
        s+='0';
        generateBinaryStrings(ans,n,i+1,0,s);
        s.pop_back();
    }
    
}
int main(){
    vector<string> ans;
    
    generateBinaryStrings(ans,3,0,0,"");

    for(string it:ans){
        cout<<it<<" "; 
    }
    cout<<endl;
}