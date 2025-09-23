// File: undirected_unweighted.cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int V = 5;                                 // vertices 0..4
    vector<vector<int>> adj(V);                // adjacency list
    auto addEdge = [&](int u,int v){
        if(u<0||u>=V||v<0||v>=V) return;
        adj[u].push_back(v);                   // u -> v
        adj[v].push_back(u);                   // v -> u (undirected)
    };

    addEdge(0,1); addEdge(0,4); addEdge(1,2);  // sample edges
    cout<<"Undirected Unweighted Graph:\n";
    for(int u=0; u<V; ++u){ cout<<u<<": "; for(int v:adj[u]) cout<<v<<" "; cout<<"\n"; }
    return 0;
}
