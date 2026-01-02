#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph{
    public:
    int V;
    vector<int> *l;
    // l is pointer to type vector of integers

    
    Graph(int V){
        this->V=V;   
        l = new vector<int> [V];
    }

    void addEdge(int u,int v){
        l[u].push_back(v);
    }

    void dfs(int node, stack<int>&st,bool visited[]){
        visited[node]=true;
        for(auto it: l[node]){
            if(!visited[it]) dfs(it,st,visited);
        }
        st.push(node);
    }
    vector<int> topoSort(){

      stack<int> st; 
      bool visited[V]={0};
      for(int i=0;i<V;i++){
        if(!visited[i]) dfs(i,st,visited);
      }

      vector<int> topo;
      while(!st.empty()){
        topo.push_back(st.top());
        st.pop();
      }
      return topo;
    }
};

int main(){
    Graph G(6);
    G.addEdge(5,0);
    G.addEdge(5,2);
    G.addEdge(2,3);
    G.addEdge(3,1);
    G.addEdge(4,0);
    G.addEdge(4,1);

    auto t=G.topoSort();
    for(int i: t){
        cout<<i<<" ";
    }
    cout<<endl;
}

