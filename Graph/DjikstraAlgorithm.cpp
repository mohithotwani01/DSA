#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<pair<int, int>>> &graph, int u, int v, int w = 1) {
    graph[u].push_back(make_pair(v,w));
    graph[v].push_back(make_pair(u,w));
}

void printGraph(vector<vector<pair<int, int>>> graph) {
    int v = graph.size() - 1;
    for (int i = 0; i <= v; i++) {
        cout << i << ": ";
        for (auto ele:graph[i]) {
            cout << ele.first << "@" << ele.second << " ";
        }
        cout << endl;
    }
}

void printPath(int dest, vector<int> parent) {
    if (parent[dest] == -1) {
        return;
    }
    printPath(parent[dest], parent);
    cout << "-->" << dest;
}

int dijkstraAlgorithm(vector<vector<pair<int,int>>> graph, int src, int dest) {
    // Useful Data Structures
    vector<int> dist(graph.size(), INT_MAX);
    set<pair<int, int>> s;
    vector<int> parent(graph.size(), -1);

    // Initialization
    dist[src] = 0;
    s.insert({0,src});

    while (!s.empty()) {
        auto it = s.begin();
        int node = it->second;
        int distTillNow = it->first;

        s.erase(it); // Pop

        // Iterate over the neighbors of the node
        for (auto nbrPair:graph[node]) {
            
            int nbr = nbrPair.first;
            int distNode = nbrPair.second;

            if (distTillNow + distNode < dist[nbr]) {

                // remove if node already exists
                auto f = s.find({dist[nbr], nbr});
                if (f != s.end()) {
                    s.erase(f);
                }

                parent[nbr] = node;
                dist[nbr] = distTillNow + distNode;
                s.insert({dist[nbr], nbr});
            }

        }

    }
    for (int i = 1; i < dist.size(); i++) {
        cout << "Shortest dist from " << src << " to " << i << " is " << dist[i] << endl;
    }
    cout << src;
    printPath(dest, parent);
    cout << endl;
    return dist[dest];
}


int main() {
    int v;
    cin >> v;
    vector<vector<pair<int, int>>> graph(v+1);
    int e;
    cin >> e;
    for (int i = 0; i < e; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        addEdge(graph, u, v, w);
    }
    int src = 1, dest = v;
    cout << dijkstraAlgorithm(graph, src, dest) << endl;
}