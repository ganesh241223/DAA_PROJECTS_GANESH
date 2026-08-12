#include <iostream>
#include <vector>
#include <queue>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);   // Undirected graph
    }

    void DFSUtil(int v, vector<bool> &visited) {
        visited[v] = true;
        cout << v << " ";

        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        DFSUtil(start, visited);
    }

    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            cout << node << " ";

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
};

int main() {
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    Graph g(V);

    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter edges (u v):\n";

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int start;

    cout << "Enter starting vertex: ";
    cin >> start;

    // DFS Time Analysis
    auto startDFS = high_resolution_clock::now();

    cout << "\nDFS Traversal: ";
    g.DFS(start);

    auto endDFS = high_resolution_clock::now();

    auto dfsTime =
        duration_cast<nanoseconds>(endDFS - startDFS);

    // BFS Time Analysis
    auto startBFS = high_resolution_clock::now();

    cout << "\n\nBFS Traversal: ";
    g.BFS(start);

    auto endBFS = high_resolution_clock::now();

    auto bfsTime =
        duration_cast<nanoseconds>(endBFS - startBFS);

    cout << "\n\nExecution Time:";

    cout << "\nDFS: "
         << dfsTime.count() << " ns";

    cout << "\nBFS: "
         << bfsTime.count() << " ns";

    return 0;
}

Enter number of vertices: 6
Enter number of edges: 7
Enter edges (u v):
0 1
0 3
1 2
1 4
2 5
3 4
4 5
Enter starting vertex: 2

DFS Traversal: 2 1 0 3 4 5

BFS Traversal: 2 1 5 0 4 3

Execution Time:
DFS: 3500 ns
BFS: 2300 ns