#include <iostream>
#include <vector>
#include <queue>

class Graph {
private:
    int vertices;
    bool directed;
    std::vector<int> *al;
public:
    Graph(int vertices, bool directed) : vertices(vertices), directed(directed), al(new std::vector<int>[vertices]) {}

    std::vector<int> adj(int vertex) {
        return al[vertex];
    }

    void addEdge(int from, int to) {
        al[from].push_back(to);

        if (!directed) {
            al[to].push_back(from);
        }
    }

    int verices() {
        return vertices;
    }

    void dfs(int vert, bool *visited) {
        // Mark as visited
        visited[vert] = true;

        // Do something
        std::cout << "Visited vertex: " << vert << '\n';

        // Travers others
        for (auto v: adj(vert)) {
            if (!visited[v]) {
                dfs(v, visited);
            }
        }
    }

    void bfsPrint() {
        // Support structures
        std::queue<int> q;
        bool *visited = new bool[vertices];

        // First vertex
        int startVert = 0;
        q.push(startVert);
        visited[startVert] = true;

        while(!q.empty()) {
            // Process
            int v = q.front();
            std::cout << v << ' ';
            q.pop();

            // Add adj to q
            for(int vert : adj(v)) {
                if(!visited[vert]) {
                    q.push(vert);
                    visited[vert] = true;
                }
            }
        }
    }

    void dfsPrint() {
        bool *visited = new bool[vertices];

        dfs(0, visited);

        delete[] visited;
    }
};


int main() {
    int e, v;
    std::cin >> e >> v;

    Graph g(6, false);
    for(int i = 0; i < e; i++) {
        int from, to;
        std::cin >> from >> to;

        g.addEdge(from, to);
    }

    g.bfsPrint();

    return 0;
}
