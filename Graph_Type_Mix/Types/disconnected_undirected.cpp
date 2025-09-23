// File: disconnected_undirected.cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int V=6;
    vector<vector<int>> adj(V);
    auto add=[&](int u,int v){ adj[u].push_back(v); adj[v].push_back(u); };
    add(0,1); add(1,2);   // component A: {0,1,2}
    add(3,4);             // component B: {3,4}
    // vertex 5 isolated
    vector<int> vis(V,0);
    int comps=0;
    for(int i=0;i<V;i++){
        if(!vis[i]){ comps++; queue<int>q; q.push(i); vis[i]=1;
            while(!q.empty()){ int u=q.front(); q.pop(); for(int v: adj[u]) if(!vis[v]){vis[v]=1; q.push(v);} }
        }
    }
    cout<<"Number of connected components: "<<comps<<"\n"; // expect 3
    return 0;
}
