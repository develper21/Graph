#include <bits/stdc++.h>
using namespace std;

void bfs(int sp, vector<vector<pair<int, int>>> &adj, int vertise){
    vector<bool> visited (vertise, 0);
    queue<int> q;
    q.push(sp);
    visited[sp] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << "";
        
        for(int i = 0; i < adj[node].size(); i++){
            int nbr = adj[node][i].first;
            int wt  = adj[node][i].second;
    
            if(!visited[nbr]){
                visited[nbr] = true;
                q.push(nbr);
            }
        }

    }
    cout << endl;
}

int main() {
    int vertices, edges;
    cin >> vertices >> edges;

    vector<vector<pair<int, int>>> adj(vertices);

    for(int i = 0; i < edges; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int start;
    cin >> start;
    bfs(start, adj, vertices);

    return 0;
}