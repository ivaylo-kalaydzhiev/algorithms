#include <iostream>
#include <vector>

// Graph representations
// Adjacency list
// Adjacency matrix

class Graph {
private:
    std::vector<int> *adjList;
    int verticesCount;
    bool directed;

public:
    Graph(int verticesCount, bool directed) : verticesCount(verticesCount), directed(directed) {
        adjList = new std::vector<int>[verticesCount];
    }

    // Adds edge from v to w
    void addEdge(int v, int w) {
        adjList[v].push_back(w);
        if(!directed) {
            adjList[w].push_back(v);
        }
    }

    // Returns a vector of all vertices adj to edge v
    std::vector<int> adjTo(int v) {
        return adjList[v];
    }

    int getVerticesCount() {
        return verticesCount;
    }
};

int main() {
    int v, e;
    std::cin >> v >> e;

    Graph graph(v, false);
    for(int i = 0; i < e; i++) {
        int from, to;
        std::cin >> from >> to;
        graph.addEdge(from, to);
    }

    return 0;
}
