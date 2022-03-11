#include <bits/stdc++.h>
using namespace std;
#define INF 1000

vector<vector<int>> floydWarshall(vector<vector<int>> dist) {
    int v = dist.size() - 1;
    // Phases, in kth phase we include vertices (1,2,....k) as intermediate vertices
    for (int k = 1; k <= v; k++) {
        // Iterate over entire 2-D matrix
        for (int i = 1; i <= v; i++){
            for (int j = 1; j <= v; j++) {
                // If vertex k is included then can we minimise the distance?
                // dist[i][k] + dist[k][j] < dist[i][j]
                if (dist[i][k] < INT_MAX and dist[k][j] < INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
    }
    for (int i = 1; i <= v; i++) {
        if (dist[i][i] < 0) {
            cout << "Negative Weight Cycle Detected" << endl;
            exit(0);
        }
    }
    return dist;
}

int main() {
    int v,e;
    cin >> v >> e;
    vector<vector<int>> graph(v+1, vector<int>(v+1, INF));
    for (int i = 0; i <= v; i++) graph[i][i] = 0;
    for (int i = 0; i < e; i++) {
        int to, from, weight;
        cin >> to >> from >> weight;
        graph[to][from] = weight;
    }
    vector<vector<int>> dist = floydWarshall(graph);
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}