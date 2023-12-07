#include <iostream>
#include <vector>

// Graph representations
// Adjacency list
// Adjacency matrix


int main() {
    int v, e;
    std::cin >> v >> e;

    AMGraph graph(v, false);
    for(int i = 0; i < e; i++) {
        int from, to;
        std::cin >> from >> to;
        graph.addEdge(from, to);
    }

    return 0;
}
