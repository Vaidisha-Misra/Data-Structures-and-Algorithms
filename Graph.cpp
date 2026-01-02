#include<iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph{
    int V;
    vector<int> *l;
    // l is pointer to type vector of integers

    public:
    Graph(int V){
        this->V=V;
        l = new vector<int> [V];
    }

    void addEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    vector<int> bfs(){
        vector<int> bfsv;
        queue<int> Q;
        bool visited[V]={false};

        Q.push(0);
        visited[0]=true;

        while(!Q.empty()){
            int u=Q.front();
            bfsv.push_back(u);

            for(int v: l[u]){
                if(!visited[v]){
                    Q.push(v);
                    visited[v]=true;
                }
            }
            Q.pop();
        }
        return bfsv;
    }

    void dfsHelper(int u,bool visited[],vector<int> &dfsv){
        dfsv.push_back(u);
        visited[u]=true;

        for(int v:l[u]){
            if(!visited[v]){
                dfsHelper(v,visited,dfsv);
            }
        }
    }

    vector<int> dfs(){
        vector<int> dfsv;
        bool visited[V]={false};
        int src=0;

        dfsHelper(src,visited,dfsv);
        return dfsv;
    }
};