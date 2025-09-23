// File: undirected_weighted.cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int V=4;
    vector<vector<pair<int,int>>> adj(V);      // adj[u] = {v,weight}
    auto addEdge = [&](int u,int v,int w){
        if(u<0||u>=V||v<0||v>=V) return;
        adj[u].push_back({v,w}); adj[v].push_back({u,w}); // symmetric
    };

    addEdge(0,1,10); addEdge(0,2,5); addEdge(2,3,9);
    cout<<"Undirected Weighted Graph:\n";
    for(int u=0; u<V; ++u){
        cout<<u<<": ";
        for(auto &pr: adj[u]) cout<<"("<<pr.first<<","<<pr.second<<") ";
        cout<<"\n";
    }
    return 0;
}
