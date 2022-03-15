#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>> graph, int src, vector<bool> &visited, vector<bool> &stack) {
    // arrive at node
    visited[src] = true;
    stack[src] = true;

    // return true if backedge is found here itself
    for (int nbr:graph[src]) {
        if (visited[nbr] == false) {
            // The next node can form a cycle
            if (dfs(graph, nbr, visited, stack)) return true;
        } else if (stack[nbr] == true) { // If it is already present in a stack
            return true;
        }
    }

    // going back
    stack[src] = false;
    return false;
}

bool containsCycle(vector<vector<int>> graph) {
    int v = graph.size();
    vector<bool> visited(v, false);
    vector<bool> stack(v, false);

    for (int i = 0; i < v; i++) {
        int source = i;
        if (visited[source]) continue;
        // If backedge is found
        if (dfs(graph,i,visited,stack)) return true;

    }
    return false;
}

int main() {
    int v, e;
    cin >> v >> e;
    vector<vector<int>> graph(v+1);
    for (int i = 0; i < e; i++) {
        int to, from;
        cin >> to >> from;
        graph[to].push_back(from);
    }
    cout << boolalpha << containsCycle(graph) << endl;
}