#include <bits/stdc++.h>
using namespace std;
void insert(stack<int> &st,int temp){
    if(st.empty() || temp>=st.top()){
        st.push(temp);
        return;
    }
    int val=st.top();
    st.pop();
    insert(st,temp);
    st.push(val);
}
void sortStack(stack <int> &st){
    if(st.empty()) return;
    int temp=st.top();
    st.pop();
    sortStack(st);
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
    sortStack(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;

}
