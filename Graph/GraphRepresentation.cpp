// Undirected Graph Representation
#include <bits/stdc++.h>
using namespace std;

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
    for (int i = 1; i <= v; i++) {
        cout << i << "-->";
        for (int j = 0; j < graph[i].size(); j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}