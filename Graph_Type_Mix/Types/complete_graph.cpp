// File: complete_graph.cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n = 4; // K4
    vector<vector<int>> adj(n);
    for(int u=0; u<n; ++u){
        for(int v=u+1; v<n; ++v){
            adj[u].push_back(v); adj[v].push_back(u); // connect every pair once
        }
    }
    cout<<"Complete Graph K"<<n<<":\n";
    for(int u=0; u<n; ++u){ cout<<u<<": "; for(int v:adj[u]) cout<<v<<" "; cout<<"\n"; }
    return 0;
}
