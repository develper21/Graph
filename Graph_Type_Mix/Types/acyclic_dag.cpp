// File: acyclic_dag.cpp
#include <bits/stdc++.h>
using namespace std;

// detect cycle in directed graph using DFS + recursion stack
bool dfsCycleDir(int u, vector<int>& vis, vector<int>& instack, vector<vector<int>>& adj){
    vis[u]=1; instack[u]=1;
    for(int v: adj[u]){
        if(!vis[v] && dfsCycleDir(v,vis,instack,adj)) return true;
        if(instack[v]) return true; // back-edge -> cycle
    }
    instack[u]=0;
    return false;
}

int main(){
    int V=4;
    vector<vector<int>> adj(V);
    auto add=[&](int u,int v){ adj[u].push_back(v); };
    add(0,1); add(0,2); add(1,3); // 0->1->3 and 0->2 (no back edge) => acyclic
    vector<int> vis(V,0), instack(V,0);
    bool cycle=false;
    for(int i=0;i<V;i++) if(!vis[i]) if(dfsCycleDir(i,vis,instack,adj)) { cycle=true; break; }
    cout<<"Directed Acyclic? "<<(!cycle?"Yes\n":"No\n");
    return 0;
}
