// File: connected_undirected.cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int V=5;
    vector<vector<int>> adj(V);
    auto add=[&](int u,int v){ adj[u].push_back(v); adj[v].push_back(u); };
    add(0,1); add(1,2); add(2,3); add(3,4);   // chain connects all nodes
    vector<int> vis(V,0);
    queue<int> q; q.push(0); vis[0]=1;
    while(!q.empty()){ int u=q.front(); q.pop(); for(int v: adj[u]) if(!vis[v]){ vis[v]=1; q.push(v);} }
    bool connected = true; for(int i=0;i<V;i++) if(!vis[i]) connected=false;
    cout<<"Connected Graph? "<<(connected?"Yes\n":"No\n");
    return 0;
}
