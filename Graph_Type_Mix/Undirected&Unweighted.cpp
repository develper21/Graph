// Adjacency Matrix for Undirected and Unweighted graph:

#include <iostream>
using namespace std;

class Graph {
    int V; // Number of vertices
    int** adjMatrix; // Adjacency matrix
public:
    Graph(int V);
    void addEdge(int u, int v);
    void display();
    ~Graph();
};

Graph::Graph(int V) {
    this->V = V;
    adjMatrix = new int*[V];
    for (int i = 0; i < V; i++) {
        adjMatrix[i] = new int[V];
        for (int j = 0; j < V; j++) {
            adjMatrix[i][j] = 0; // Initialize with 0
        }
    }
}

void Graph::addEdge(int u, int v) {
    adjMatrix[u][v] = 1; // Add edge from u to v
    adjMatrix[v][u] = 1; // Since the graph is undirected
}

void Graph::display() {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

Graph::~Graph() {
    for (int i = 0; i < V; i++) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
}

int main() {
    int V = 5; // Number of vertices
    Graph g(V);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << "Adjacency Matrix:" << endl;
    g.display();

    return 0;
}