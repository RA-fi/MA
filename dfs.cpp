#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;
public:
    Graph(int v) : V(v), adj(v) {}

    void addEdge(int u, int v) {
        if (u < 0 || u >= V || v < 0 || v >= V) {
            cout << "Invalid edge\n";
            return;
        }
        adj[u].push_back(v);
    }

    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";
        for (int x : adj[v]) {
            if (!visited[x])
                DFSUtil(x, visited);
        }
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        DFSUtil(start, visited);
        cout << endl;
    }

    void PrintDegrees() {
        cout << "Degrees:\n";
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << ": " << adj[i].size() << endl;
        }
    }

    void getAddjacentVertices(int v) {
        if (v < 0 || v >= V) {
            cout << "Invalid vertex\n";
            return;
        }
        cout << "Adjacent vertices of " << v << ": ";
        for (int x : adj[v]) cout << x << " ";
        cout << endl;
    }

    int getIndegree(int v) {
        int indeg = 0;
        for (int i = 0; i < V; i++) {
            for (int x : adj[i]) {
                if (x == v) indeg++;
            }
        }
        cout << "In-degree of vertex " << v << ": " << indeg << endl;
        return indeg;
    }

    int get_outdegree(int v) {
        if (v < 0 || v >= V) return -1;
        cout << "Out-degree of vertex " << v << ": " << adj[v].size() << endl;
        return adj[v].size();
    }

    void printIndegreesOutdegrees() {
        cout << "Printing indegrees and outdegrees for all vertices:\n";
        for (int v = 0; v < V; v++) {
            int indeg = 0;
            for (int i = 0; i < V; i++) {
                for (int x : adj[i]) if (x == v) indeg++;
            }
            cout << "Vertex " << v << ": In-degree = " << indeg
                 << ", Out-degree = " << adj[v].size() << endl;
        }
    }
};

int main() {
    int V, u, v;
    cout << "Enter the size of graph :";
    cin >> V;
    Graph g(V);

    cout << "Adding edges to the graph: (u , v)" << endl;
    for (int i = 0; i < V; i++) {
        cin >> u >> v;
        g.addEdge(u, v);
    }
    cout << "Edge added successfully\n";

    cout << "Depth First Traversal (starting from input vertex ): ";
    int x;
    cin >> x;
    g.DFS(x);

    g.PrintDegrees();

    for (int i = 0; i < V; i++) {
        g.getAddjacentVertices(i);
    }

    cout << "Enter vertex to get indegree: ";
    cin >> x;
    g.getIndegree(x);

    cout << "Enter vertex to get outdegree: ";
    cin >> x;
    g.get_outdegree(x);

    g.printIndegreesOutdegrees();

    return 0;
}
