// Adjacency Matrix for Undirected and Weighted graph:

#include <iostream>
using namespace std;

class Graph
{
    int V;     // No. of vertices
    int **adj; // Pointer to 2D array that will hold the adjacency matrix
public:
    Graph(int V);                      // Constructor
    void addEdge(int u, int v, int w); // function to add an edge
    void display();                    // function to display the adjacency matrix
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new int *[V];
    for (int i = 0; i < V; i++)
    {
        adj[i] = new int[V];
        for (int j = 0; j < V; j++)
            adj[i][j] = 0; // Initialize all entries as 0
    }
}
void Graph::addEdge(int u, int v, int w)
{
    adj[u][v] = w; // Add w to the edge (u,v)
    adj[v][u] = w; // Since the graph is undirected
}
void Graph::display()
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }
}
int main()
{
    int V = 5; // Number of vertices
    Graph g(V);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 4, 20);
    g.addEdge(1, 2, 30);
    g.addEdge(1, 3, 40);
    g.addEdge(1, 4, 50);
    g.addEdge(2, 3, 60);
    g.addEdge(3, 4, 70);
    g.display();
    return 0;
}