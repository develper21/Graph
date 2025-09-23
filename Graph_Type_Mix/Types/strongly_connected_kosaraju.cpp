// File: strongly_connected_kosaraju.cpp
#include <bits/stdc++.h>
using namespace std;

void dfs1(int u, vector<int>& vis, vector<vector<int>>& adj, vector<int>& order){
    vis[u]=1;
    for(int v: adj[u]) if(!vis[v]) dfs1(v,vis,adj,order);
    order.push_back(u);
}
void dfs2(int u, vector<int>& vis, vector<vector<int>>& radj){
    vis[u]=1;
    for(int v: radj[u]) if(!vis[v]) dfs2(v,vis,radj);
}

int main(){
    int V=5;
    vector<vector<int>> adj(V), radj(V);
    auto addEdge=[&](int u,int v){
        adj[u].push_back(v); radj[v].push_back(u); // radj is reversed graph
    };
    // build graph with two SCCs: {0,1,2} strongly connected among themselves and {3,4}
    addEdge(0,1); addEdge(1,2); addEdge(2,0); // SCC1
    addEdge(3,4); addEdge(4,3);               // SCC2
    vector<int> vis(V,0), order;
    for(int i=0;i<V;i++) if(!vis[i]) dfs1(i,vis,adj,order);
    fill(vis.begin(), vis.end(), 0);
    int sccCount=0;
    for(int i=V-1;i>=0;i--){
        int v=order[i];
        if(!vis[v]){ dfs2(v,vis,radj); sccCount++; }
    }
    cout<<"Strongly connected components count: "<<sccCount<<"\n"; // expect 3 if isolated nodes counted
    return 0;
}
