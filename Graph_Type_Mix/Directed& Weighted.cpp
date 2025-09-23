// Adjacency Matrix for Directed and Weighted graph:
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
    int V = 4; // Number of vertices
    Graph g(V);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 0, 4);
    g.addEdge(2, 3, 6);
    g.addEdge(3, 3, 1);
    g.display();
    return 0;
}