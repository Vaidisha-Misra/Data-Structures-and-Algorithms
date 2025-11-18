#include <iostream>
#include<vector>
#include<queue>

using namespace std;

void bfs_visit(vector<vector<int>> &adj,int n,vector<int> &distance,vector<int> &parent,vector<int> &visited,vector<int> bfs){
    queue<int> q;
    distance[n]=0;
    visited[n]=1;
    q.push(n);

    while(!q.empty()){
        int curr=q.front();
        bfs.push_back(curr);
        for(int i=0;i<adj[curr].size();i++){
            if(visited[adj[curr][i]]==0){
                visited[adj[curr][i]]=1;
                parent[adj[curr][i]]=curr;
                distance[adj[curr][i]]=1 + distance[curr];
                q.push(adj[curr][i]);
            }
        }
        visited[curr]=2;
        q.pop();
    }

}
void BFS(vector<vector<int>> &adj,int source ,int v, vector<int> &visited,vector<int> &parent,vector<int> &distance,vector<int> &bfs){
    
    bfs_visit(adj,source,distance,parent,visited,bfs);
    for(int i=0;i<v;i++){
        if(visited[i]==0){
            bfs_visit(adj,i,distance,parent,visited,bfs);
        }
    }
    
}


int main(){
    int v;
    int e;
    vector<vector<int>> adj(v);
    cin>>v>>e;
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        adj[b].push_back(a);
        adj[a].push_back(b);
    }
    vector<int> bfs(v);
    vector<int> visited(v,0);
    vector<int> parent(v);
    vector<int> distance(v);
    BFS(adj,0,v,visited,parent,distance,bfs);

    cout<<endl;
    for(int i=0;i<v;i++){
        cout<<parent[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<v;i++){
        cout<<distance[i]<<" ";
    }
    cout<<endl;
}