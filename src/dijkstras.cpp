#include "dijkstras.h"
#include <queue>
#include <algorithm>
#include <iostream>

struct DistVertex {
    int dist;
    int vertex;
    DistVertex(int d, int v) : dist(d), vertex(v) {}
};

struct DistCompare {
    bool operator()(const DistVertex& a, const DistVertex& b) {
        return a.dist > b.dist;
    }
};

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    int n = G.numVertices;
    vector<int> dist(n, INF);
    previous.assign(n, -1);
    vector<bool> visited(n, false);

    dist[source] = 0;
    priority_queue<DistVertex, vector<DistVertex>, DistCompare> pq;
    pq.push(DistVertex(0, source));

    while (!pq.empty()) {
        auto [currentDist, u] = pq.top();
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;
        for (auto &edge : G[u]) {
            int v = edge.dst;
            int w = edge.weight;
            if (!visited[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                previous[v] = u;
                pq.push(DistVertex(dist[v], v));
            }
        }
    }
    return dist;
}

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination) {
    if (destination < 0 || destination >= (int)distances.size() ||
        distances[destination] == INF) {
        return {};
    }
    vector<int> path;
    for (int v = destination; v != -1; v = previous[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
}

void print_path(const vector<int>& v, int total) {
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i+1 < v.size()) cout << " ";
    }
    cout << "\nTotal cost: " << total << endl;
}