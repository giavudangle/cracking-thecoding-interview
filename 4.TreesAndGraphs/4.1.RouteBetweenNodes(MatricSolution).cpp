/**
 * 4.1.Route Between Nodes :
 *
 * Given a directed graph, design an algorithm to find out
 * whether there is a route between two nodes.
 *
 * @author VuDang
 */

#include <iostream>
#include <vector>


class Graph {
public:
    int n = 0;
    std::vector<std::vector<int>>adj;
    std::vector<std::vector<bool>>matrix;

    Graph(int n) {
        this->n = n;
        adj.resize(n);
    }

    // undirected graph
    void addUndirectedEdge(int u,int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // directed graph
    void addDirectedEdge(int u, int v) {
        adj[u].push_back(v);     
    }

    // Convert to Adjagency Matrices
    void convertFromListToMatrix() {
        matrix.resize(this->n);
        for (int i = 0; i < adj.size(); i++) {
            if (adj[i].size() > 0) {
                matrix[i].resize(this->n);
                for (int j = 0; j < adj[i].size(); j++) {
                    int curr = adj[i][j];
                    matrix[i][curr] = true;
                }
            }
        }
    }

    // is a route between two nodes ?
    bool isRouteBetweenTwoNodes(int u, int v) {
        convertFromListToMatrix();
        return this->matrix[u][v] > 0 ? true : false;
    }




    void printGraph() {
        int n = this->n;
        for (int i = 0; i < n; i++) {
            std::cout << i << " ";
            if (adj[i].size() == 0) {
                std::cout << "NULL";
            }
            else {
                for (int x : adj[i]) {
                    std::cout << "-> " << x;
                }
            }
            
            std::cout << std::endl;
        }
    }
};


int main() {

    Graph* g = new Graph(5);
    g->addDirectedEdge(0, 1);
    g->addDirectedEdge(0, 2);
    g->addDirectedEdge(2, 1);
    g->addDirectedEdge(2, 3);
    g->addDirectedEdge(3, 2);
    g->printGraph();
    g->isRouteBetweenTwoNodes(0, 3) == 1 ? std::cout << "Yes" : std::cout << "No";




    return 0;
}