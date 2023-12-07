//
// Created by Ivaylo Kalaydzhiev on 7.12.23.
//
// Graph implemented with Adj List

#include <iostream>
#include <vector>

class ALGraph {
private:
    std::vector<int> *adjList;
    int verticesCount;
    bool directed;

public:
    ALGraph(int verticesCount, bool directed) : verticesCount(verticesCount), directed(directed) {
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