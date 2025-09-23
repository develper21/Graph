// File: directed_weighted.cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int V = 4;
    vector<vector<pair<int,int>>> adj(V);      // adj[u] = list of {v, weight}
    auto addEdge = [&](int u,int v,int w){
        if(u<0||u>=V||v<0||v>=V) return;
        adj[u].push_back({v,w});               // add directed weighted edge u->v (weight w)
    };

    addEdge(0,1,7); addEdge(0,2,3); addEdge(2,3,1);
    cout<<"Directed Weighted Graph:\n";
    for(int u=0; u<V; ++u){
        cout<<u<<" -> ";
        for(auto &p: adj[u]) cout<<"("<<p.first<<","<<p.second<<") ";
        cout<<"\n";
    }
    return 0;
}
