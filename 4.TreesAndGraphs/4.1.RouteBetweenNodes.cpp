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
#include <queue>


class Graph {
public:
   
    bool* visited;
    int n;
    std::vector<std::vector<int>>adj;
    Graph(int n) {
        this->n = n;
        adj.resize(n);
    }

    // undirected graph
    void addUndirectedEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // directed graph
    void addDirectedEdge(int u, int v) {
        adj[u].push_back(v);
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

    void BFS(int s) {
        visited = new bool[this->n];
        for (int i = 0; i < this->n; i++) visited[i] = false;

        std::queue<int> queue;

        visited[s] = true;
        queue.push(s);
        std::cout << s << " ";

        while (!queue.empty()) {
            s = queue.front();
            queue.pop();
            for (std::vector<int>::iterator it = adj[s].begin(); it != adj[s].end(); ++it) {
                if (!visited[*it]) {
                    std::cout << *it << " ";

                    visited[*it] = true;
                    queue.push(*it);
                }
            }
        }
    }

    bool isRouteBetweenNodes(int s, int v) {
        if (s == v) return true;
        visited = new bool[this->n];
        for (int i = 0; i < this->n; i++) visited[i] = false;

        std::queue<int> queue;

        visited[s] = true;
        queue.push(s);

        while (!queue.empty()) {
            s = queue.front();
            queue.pop();
            for (std::vector<int>::iterator it = adj[s].begin(); it != adj[s].end(); ++it) {
                if (!visited[*it]) {
                    if (*it == v) return true;
                    visited[*it] = true;
                    queue.push(*it);
                }
            }
        }
        return false;
    }

   
};



int main() {

    Graph* g = new Graph(4);
    g->addDirectedEdge(0, 1);
    g->addDirectedEdge(0, 2);
    g->addDirectedEdge(1, 2);
    //g->addDirectedEdge(2, 0);
    g->addDirectedEdge(2, 3);
    g->addDirectedEdge(3, 3);

    //g->printGraph();
    g->isRouteBetweenNodes(1, 0) == 1 ? std::cout << "Yes" : std::cout << "No";
    



    return 0;
}