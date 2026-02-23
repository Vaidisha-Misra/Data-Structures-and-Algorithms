#include <bits/stdc++.h>
using namespace std;
void insert(stack<int>& st,int temp){
    if(st.empty()){
        st.push(temp);
        return;
    }
    int val=st.top();
    st.pop();
    insert(st,temp);
    st.push(val);
}
void ReverseStack(stack<int> &st){
    if(st.empty()) return;
    int temp=st.top();
    st.pop();
    ReverseStack(st);
    insert(st,temp);
}
int main(){
    int n;
    cin>>n;
    stack <int> s;
    int val;
    while(n){
       cin>>val;
       s.push(val);
       n--; 
    }
    ReverseStack(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;

}
