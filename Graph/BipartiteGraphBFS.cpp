#include <bits/stdc++.h>
using namespace std;

bool bipartiteBFS(int src, vector<vector<int>> graph, vector<int> &visited) {
    queue<int> q;
    q.push(src);
    visited[src] = 1;
    while (!q.empty()) {
        src = q.front();
        q.pop();
        for (auto nbr:graph[src]) {
            if (visited[nbr] == -1) {
                visited[nbr] = 1 - visited[src];
                q.push(nbr);
            } else if (visited[nbr] == visited[src]) {
                return false;
            }
        }
    }
    return true;
}

bool checkBipartiteBFS(vector<vector<int>> graph) {
    int v = graph.size();
    vector<int> visited(v, -1);
    for (int i = 0; i < v; i++) {
        if (visited[i] == -1) {
            if (bipartiteBFS(i, graph, visited) == false) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int v,e;
    cin >> v >> e;
    vector<vector<int>> graph(v);
    for (int i = 0; i < e; i++) {
        int to,from;
        cin >> to >> from;
        graph[to].push_back(from);
        graph[from].push_back(to);
    } 

    // BFS or DFS, by coloring the nodes at each step 
    // current node has color 0 and nbr should have color 1
    cout << boolalpha << checkBipartiteBFS(graph) << endl;
}