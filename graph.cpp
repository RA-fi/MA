#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int V;
    bool directed;
    vector<vector<int>> adj;

public:
    Graph(int vertices, bool dir) : V(vertices), directed(dir) {
        adj.resize(V);
    }

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        if (!directed) adj[v].push_back(u);
    }

    void dfs_util(int v, vector<bool> &visited) {
        visited[v] = true;
        cout << v << " ";
        for (int nbr : adj[v]) {
            if (!visited[nbr]) dfs_util(nbr, visited);
        }
    }

    void full_dfs() {
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) dfs_util(i, visited);
        }
        cout << "\n";
    }

    void bfs_util(int s, vector<bool> &visited) {
        queue<int> q;
        visited[s] = true;
        q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            cout << u << " ";
            for (int nbr : adj[u]) {
                if (!visited[nbr]) {
                    visited[nbr] = true;
                    q.push(nbr);
                }
            }
        }
    }

    void full_bfs() {
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) bfs_util(i, visited);
        }
        cout << "\n";
    }

    void print_degrees() {
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << ": " << adj[i].size() << "\n";
        }
    }

    vector<int> get_adjacent_vertices(int v) {
        return adj[v];
    }

    int get_indegree(int v) {
        if (!directed) return -1;
        int count = 0;
        for (int i = 0; i < V; i++) {
            for (int nbr : adj[i]) {
                if (nbr == v) count++;
            }
        }
        return count;
    }

    int get_outdegree(int v) {
        if (!directed) return -1;
        return adj[v].size();
    }

    void print_indegree_outdegree() {
        if (!directed) {
            cout << "Graph is undirected, no indegree/outdegree.\n";
            return;
        }
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << ": In-degree = " << get_indegree(i)
                 << ", Out-degree = " << get_outdegree(i) << "\n";
        }
    }
};

int main() {
    int V, E, D;
    cout << "Enter number of vertices, edges, directed(1)/undirected(0): ";
    cin >> V >> E >> D;
    Graph g(V, D == 1);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v; cin >> u >> v;
        g.add_edge(u, v);
    }

    int start;
    cout << "Enter start vertex for BFS and DFS: ";
    cin >> start;

    cout << "DFS Traversal: ";
    {
        vector<bool> visited(V, false);
        g.dfs_util(start, visited);
        for (int i = 0; i < V; i++)
            if (!visited[i])
                g.dfs_util(i, visited);
    }
    cout << "\n";

    cout << "BFS Traversal: ";
    {
        vector<bool> visited(V, false);
        g.bfs_util(start, visited);
        for (int i = 0; i < V; i++)
            if (!visited[i])
                g.bfs_util(i, visited);
    }
    cout << "\n";

    cout << "Degrees:\n";
    g.print_degrees();

    cout << "Indegree and Outdegree:\n";
    g.print_indegree_outdegree();

    return 0;
}
