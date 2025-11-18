#include <iostream>
#include<vector>
#include<queue>

using namespace std;

void bfs_visit(vector<vector<int>> &adj,int n,vector<int> &distance,vector<int> &parent,vector<int> &visited,vector<int> &bfs){
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

void dfs_visit(vector<vector<int>> &adj,int n,vector<int> &visited,vector<int> &parent,vector<int> &start,vector<int> &end,vector<int> &dfs,int &timer){
    visited[n]=1;
    timer++;
    start[n]=timer;
    dfs.push_back(n);
    for(int i=0;i<adj[n].size();i++){
        if(visited[adj[n][i]]==0){
            parent[adj[n][i]]=n;
            dfs_visit(adj,adj[n][i],visited,parent,start,end,dfs,timer);
        }
    }
    visited[n]=2;
    timer++;
    end[n]=timer;
}
void DFS(vector<vector<int>> &adj,int source ,int v, vector<int> &visited,vector<int> &parent,vector<int> &start,vector<int> &end,vector<int> &dfs){
    int timer=0;
    dfs_visit(adj,source,visited,parent,start,end,dfs,timer);
    for(int i=0;i<v;i++){
        if(visited[i]==0){
            dfs_visit(adj,i,visited,parent,start,end,dfs,timer);
        }
    }
    
}


int main(){
    int v;
    int e;
    
    cin>>v>>e;
    vector<vector<int>> adj(v);
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        adj[b].push_back(a);
        adj[a].push_back(b);
    }
    vector<int> bfs;
    vector<int> bvisited(v,0);
    vector<int> bparent(v);
    vector<int> bdistance(v);
    BFS(adj,0,v,bvisited,bparent,bdistance,bfs);
    for(int i=0;i<v;i++){
        cout<<bfs[i]<<" ";
    }
    cout<<endl;
    
    for(int i=0;i<v;i++){
        cout<<bparent[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<v;i++){
        cout<<bdistance[i]<<" ";
    }
    cout<<endl;

    vector<int> dfs;
    vector<int> dvisited(v,0);
    vector<int> dparent(v);
    vector<int> start(v);
    vector<int> end(v);

    DFS(adj,0,v,dvisited,dparent,start,end,dfs);
    for(int i=0;i<v;i++){
        cout<<dfs[i]<<" ";
    }
    cout<<endl;
    
    for(int i=0;i<v;i++){
        cout<<dparent[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<v;i++){
        cout<<start[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<v;i++){
        cout<<end[i]<<" ";
    }
    cout<<endl;
}