#include <iostream>
#include<list>
#include<vector>
using namespace std;
class Graph {
private:
    int N;
    int time;
    list<int>* adj;
    vector<int>parent;
    vector<int>GrayTime;
    vector<int>BlackTime;
public:
    Graph(int N) {
        this->N = N;
        adj = new list<int>[N];
        parent.resize(N, -1);
        GrayTime.resize(N, 0);
        BlackTime.resize(N, 0);
    }

    ~Graph() {
        delete[] adj;
    }

    void AddEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void printGraph() {
        for (int i{}; i < N; i++) {
            cout << i << "->";
            for (auto it = adj[i].begin(); it != adj[i].end(); it++) {
                cout << *it << "  ";
            }
            cout << endl;
        }
    }

    void DFS();
    void DFS_Visit(int u, bool *visited);
};

void Graph::DFS() {
    if (N == 0) {
        cout << "This graph is Empty, there are no vertices in it!" << endl;
        return;
    }
    bool* visited = new bool[N];
    for (int i{}; i < N; i++) {
        parent[i] = -1;
        visited[i] = false;
    }
    time = 0;
    for (int i{}; i < N; i++) {
        if (!visited[i]) {
            DFS_Visit(i, visited);
        }
    }
    for (int i = 0; i < N; i++)
        cout << "vertex " << i << ": " << GrayTime[i] << "/" << BlackTime[i]
        << ", parent=" << parent[i] << endl;
    delete[]visited;
}

void Graph::DFS_Visit(int u, bool* visited) {
    visited[u] = true;
    time++;
    GrayTime[u] = time;
    for (auto v : adj[u]) {
        if (!visited[v]) {
            parent[v] = u;
            DFS_Visit(v, visited);
        }
    }
    time++;
    BlackTime[u] = time;
}

int main()
{
    Graph g(5);
    g.AddEdge(0, 1);
    g.AddEdge(0, 2);
    g.AddEdge(1, 3);
    g.AddEdge(2, 3);
    g.AddEdge(3, 4);
    g.printGraph();
    g.DFS();
}