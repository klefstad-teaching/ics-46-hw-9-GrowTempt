#include "dijkstras.h"
#include <iostream>
#include <exception>
using namespace std;

int main(int argc, char* argv[]) {
    string filename = (argc > 1) ? argv[1] : "../src/small.txt";
    Graph G;
    try {
        file_to_graph(filename, G);
    } catch(const exception& e) {
        cerr << e.what() << endl;
        return 1;
    }

    vector<int> previous;
    auto dist = dijkstra_shortest_path(G, 0, previous);

    for (int v = 0; v < G.numVertices; v++) {
        if (dist[v] == INF) {
            cout << "No path from 0 to " << v << endl;
        } else {
            auto path = extract_shortest_path(dist, previous, v);
            print_path(path, dist[v]);
        }
    }

    return 0;
}