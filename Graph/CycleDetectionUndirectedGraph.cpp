#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>> graph, int src, vector<bool> &visited, int parent) {
    visited[src] = true;

    for (auto nbr:graph[src]) {
        // skip the parent as it doesn't make cycle
        if (nbr == parent) continue;
        
        // if already visted and is not parent then cycle is present
        if (visited[nbr]) return true;

        // recursive call for dfs
        if (dfs(graph, nbr, visited, src)) return true;
    }
    return false;
}

bool containsCycle(vector<vector<int>> graph) {
    vector<bool> visited(graph.size(), false); 
    int src = 1;
    return dfs(graph, src, visited, -1);
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
    cout << boolalpha << containsCycle(graph) << endl;
}