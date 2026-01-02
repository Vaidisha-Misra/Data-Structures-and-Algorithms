#include <iostream>
#include <vector>
#include <queue>

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
    vector<int> topoSort(){
        int indegree[V]={0};
        vector<int> topo;
        for(int i=0;i<V;i++){
            for(auto it: l[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            
            for(int it:l[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
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
