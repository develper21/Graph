// File: cyclic_undirected.cpp
#include <bits/stdc++.h>
using namespace std;

// simple DFS to detect cycle in undirected graph (parent check)
bool dfs(int u, int parent, vector<int>& vis, vector<vector<int>>& adj){
    vis[u]=1;
    for(int v: adj[u]){
        if(!vis[v]){
            if(dfs(v,u,vis,adj)) return true;
        } else if(v!=parent){
            return true; // back-edge to non-parent => cycle
        }
    }
    return false;
}

int main(){
    int V=3;
    vector<vector<int>> adj(V);
    auto add=[&](int a,int b){adj[a].push_back(b); adj[b].push_back(a);};
    add(0,1); add(1,2); add(2,0); // triangle -> cycle
    vector<int> vis(V,0);
    bool hasCycle = dfs(0,-1,vis,adj);
    cout<<"Undirected cyclic graph? "<<(hasCycle?"Yes\n":"No\n");
    return 0;
}
