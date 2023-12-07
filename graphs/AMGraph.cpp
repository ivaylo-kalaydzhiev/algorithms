//
// Created by Ivaylo Kalaydzhiev on 7.12.23.
//

#include <iostream>

// Graph implemented with adj matrix
class AMGraph {
private:
    int **adjMatrix;
    int verticesCount;
    bool directed;

public:
    AMGraph(int verticesCount, bool directed) : verticesCount(verticesCount), directed(directed) {
        adjMatrix = new int*[verticesCount];
        for(int i = 0; i < verticesCount; i++) {
            adjMatrix[i] = new int[verticesCount] {};
        }
    }

    void addEdge(int from, int to) {
        adjMatrix[from][to] = 1;
        if(!directed) {
            adjMatrix[to][from] = 1;
        }
    }

    int* adjTo(int v) {
        return adjMatrix[v];
    }

    int getVerticesCount() {
        return verticesCount;
    }
};
