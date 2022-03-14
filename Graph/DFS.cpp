#include <bits/stdc++.h>
using namespace std;

void dfsHelper(vector<vector<int>> graph, int src, vector<bool> &visited) {
    visited[src] = true;
    cout << src << " ";

    for (int nbr:graph[src]) {
        if (visited[nbr]) continue;
        dfsHelper(graph, nbr, visited);
    }

}

void DFS(vector<vector<int>> graph, int src) {
    vector<bool> visited(graph.size(), false);
    dfsHelper(graph, src, visited);
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
    DFS(graph, src);
}