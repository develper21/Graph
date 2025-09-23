// File: directed_unweighted.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int V = 4;                                 // vertices 0..3
    vector<vector<int>> adj(V);                // adjacency list: adj[u] contains v where u -> v
    auto addEdge = [&](int u,int v){ if(u>=0&&u<V&&v>=0&&v<V) adj[u].push_back(v); };

    addEdge(0,1); addEdge(0,2); addEdge(2,3);  // edges: 0->1, 0->2, 2->3
    cout<<"Directed Unweighted Graph:\n";
    for(int u=0; u<V; ++u){
        cout<<u<<" -> ";
        for(int v: adj[u]) cout<<v<<" ";
        cout<<"\n";
    }
    return 0;
}
