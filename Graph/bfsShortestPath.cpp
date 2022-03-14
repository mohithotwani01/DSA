// Undirected Graph Representation
#include <bits/stdc++.h>
using namespace std;

void BFS(vector<vector<int>> graph, int src) {
    queue<int> q;
    vector<bool> visited(graph.size(), false);
    vector<int> dist(graph.size(), 0);
    vector<int> parent(graph.size(), -1);

    q.push(src);
    visited[src] = true;
    parent[src] = src;
    dist[src] = 0;

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        // Do some work for every node
        // cout << x << " ";
        for (auto nbr:graph[x]) {
            // already visited then skip
            if (visited[nbr]) continue;
            
            q.push(nbr);
            // mark as visited
            visited[nbr] = true;
            parent[nbr] = x;
            dist[nbr] = dist[x] + 1;
        }
    }

    // print the shortest distance
    for (int i = 0; i < graph.size(); i++) {
        cout << "Shortest Distance to node ";
        cout << i << " from " << src << " = " ;
        cout << dist[i] << endl;
    }

    // print path from src to destination
    int dest = 6;
    while (dest != src and dest != -1) {
        cout << dest << "<--";
        dest = parent[dest];
    }
    cout << src << endl;


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