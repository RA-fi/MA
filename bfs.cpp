#include <iostream>
#include <vector>
#include <queue>
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
        adj[v].push_back(u); // assuming undirected graph for BFS
    }

    void BFS(int start, vector<bool>& visited) {
        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int u = q.front(); q.pop();
            cout << u << " ";

            for (int w : adj[u]) {
                if (!visited[w]) {
                    visited[w] = true;
                    q.push(w);
                }
            }
        }
    }

    void full_bfs() {
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                BFS(i, visited);
            }
        }
        cout << endl;
    }
};

int main() {
    int V, u, v;
    cout << "Enter number of vertices: ";
    cin >> V;
    Graph g(V);

    cout << "Enter edges (u v) and -1 -1 to stop:\n";
    while (true) {
        cin >> u >> v;
        if (u == -1 && v == -1) break;
        g.addEdge(u, v);
    }

    cout << "BFS of the graph:\n";
    g.full_bfs();

    return 0;
}
