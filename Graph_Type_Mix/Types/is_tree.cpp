// File: is_tree.cpp
#include <bits/stdc++.h>
using namespace std;

bool dfsCycle(int u,int parent,vector<int>& vis, vector<vector<int>>& adj){
    vis[u]=1;
    for(int v: adj[u]){
        if(!vis[v]){ if(dfsCycle(v,u,vis,adj)) return true; }
        else if(v!=parent) return true;
    }
    return false;
}

int main(){
    int V=5;
    vector<vector<int>> adj(V);
    auto add=[&](int u,int v){ adj[u].push_back(v); adj[v].push_back(u); };
    // build a tree edges = V-1
    add(0,1); add(1,2); add(1,3); add(3,4); // 4 edges for 5 nodes
    vector<int> vis(V,0);
    bool hasCycle = dfsCycle(0,-1,vis,adj);
    bool connected = true; for(int i=0;i<V;i++) if(!vis[i]) connected=false;
    cout<<"Is tree? "<<((!hasCycle && connected) ? "Yes\n":"No\n");
    return 0;
}
