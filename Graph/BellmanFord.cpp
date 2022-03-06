#include <bits/stdc++.h>
using namespace std;

void printPath(int e, int src, vector<int> parent) {
    if (e == src) {
        cout << e;
        return;
    }
    printPath(parent[e], src, parent);
    cout << "-->" << e;
}

vector<int> bellmanFordAlgorithm(int v, int e, int src, vector<vector<int>> edges) {

    vector<int> dist(v+1, INT_MAX);
    vector<int> parent(v+1, -1);
    dist[src] = 0;
    
    // relax v-1 times
    for (int i = 1; i <= v-1; i++) {
        for (auto edge:edges) {
            int u = edge[0];
            int b = edge[1];
            int wt = edge[2];
            // checking INT_MAX to avoid integer overflow
            if (dist[u] != INT_MAX and dist[u] + wt < dist[b]) {
                dist[b] = dist[u]+wt;
                parent[b] = u;
            }
        }
    }

    // negative weight cycle
    for (auto edge:edges){
        int u = edge[0];
        int b = edge[1];
        int wt = edge[2];
        // checking INT_MAX to avoid integer overflow
        if (dist[u] != INT_MAX and dist[u] + wt < dist[b]) {
            cout << "Negative Weight Cycle Present" << endl;
            exit(0); 
        }
    }

    for (int i = 1; i <= v; i++) {
        printPath(i, src, parent);
        cout << "@" << dist[i] << endl;
    }

    return dist;

}


int main() {
    int v,e;
    cin >> v >> e;

    // edges list
    vector<vector<int>> edges;

    for (int i = 0; i < e; i++) {
        int u,b,wt;
        cin >> u >> b >> wt;
        edges.push_back({u,b,wt});
    }

    // bellman ford 
    int src = 1;
    bellmanFordAlgorithm(v,e,src,edges);

    return 0;
}