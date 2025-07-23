#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V + 1); // 1-indexed
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool dfsCycle(int v, vector<bool>& visited, int parent) {
        visited[v] = true;
        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                if (dfsCycle(neighbor, visited, v)) return true;
            } else if (neighbor != parent) {
                return true; // Cycle detected
            }
        }
        return false;
    }

    bool hasCycle() {
        vector<bool> visited(V + 1, false);
        for (int i = 1; i <= V; ++i) {
            if (!visited[i]) {
                if (dfsCycle(i, visited, -1)) return true;
            }
        }
        return false;
    }

    void bfs(int start) {
        vector<bool> visited(V + 1, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int u = q.front(); q.pop();
            cout << u << " ";
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }

    void dfs(int start) {
        vector<bool> visited(V + 1, false);
        dfsUtil(start, visited);
        cout << endl;
    }
    void dfsUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";
        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                dfsUtil(neighbor, visited);
            }
        }
    }
};

int main() {
    Graph g(8);
    vector<pair<int, int>> edges = {{1,2},{2,3},{3,4},{4,1},{4,5},{5,6},{6,7},{7,8},{8,5}};
    
    for (auto edge : edges) {
        g.addEdge(edge.first, edge.second);
    }

    cout << "BFS from node 1: ";
    g.bfs(1);

    if (g.hasCycle())
        cout << "Cycle detected in the graph." << endl;
    else
        cout << "No cycle in the graph." << endl;
    
    cout << "DFS from node 1: ";
    g.dfs(1);
    cout << endl;

    return 0;
}
