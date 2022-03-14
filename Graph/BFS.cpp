// Undirected Graph Representation
#include <bits/stdc++.h>
using namespace std;

void BFS(vector<vector<int>> graph, int src) {
    queue<int> q;
    vector<bool> visited(graph.size(), false);

    q.push(src);
    visited[src] = true;

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        // Do some work for every node
        cout << x << " ";
        for (auto nbr:graph[x]) {
            // already visited then skip
            if (visited[nbr]) continue;
            
            q.push(nbr);
            // mark as visited
            visited[nbr] = true;
        }
    }
}

int main() {
    int v, e;
    cin >> v >> e;
    vector<vector<int>> graph(v+1);
    for (int i = 0; i < e; i++) {
        int to, from;
        cin >> to >> from;
        graph[to].push_back(from);
        graph[from].push_back(to);
    }
    int src = 1;
    BFS(graph, src);
}