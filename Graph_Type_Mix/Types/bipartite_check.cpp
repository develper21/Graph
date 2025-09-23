// File: bipartite_check.cpp
#include <bits/stdc++.h>
using namespace std;

bool isBipartite(int V, vector<vector<int>>& adj){
    vector<int> color(V, -1);
    for(int s=0; s<V; ++s){
        if(color[s]!=-1) continue;
        queue<int> q; q.push(s); color[s]=0;
        while(!q.empty()){
            int u=q.front(); q.pop();
            for(int v: adj[u]){
                if(color[v]==-1){ color[v]=color[u]^1; q.push(v); }
                else if(color[v]==color[u]) return false;
            }
        }
    }
    return true;
}

int main(){
    int V=5;
    vector<vector<int>> adj(V);
    auto add=[&](int u,int v){ adj[u].push_back(v); adj[v].push_back(u); };
    // bipartite example: edges between {0,1,2} and {3,4}
    add(0,3); add(1,3); add(2,4);
    cout<<"Is bipartite? "<<(isBipartite(V,adj)?"Yes\n":"No\n");
    // triangle (0-1,1-2,2-0) is not bipartite
    vector<vector<int>> tri(3); tri[0]={1,2}; tri[1]={0,2}; tri[2]={0,1};
    cout<<"Triangle bipartite? "<<(isBipartite(3,tri)?"Yes\n":"No\n");
    return 0;
}
