
#include <iostream>
#include <list>
#include <map>
#include <vector>

int num_b;
int t;

std::vector<bool> visited;
std::vector<int> disc;
std::vector<int> low;
std::vector<int> parent;

class Graph
{
private:
    int V;                  // vertices
    std::list<int> *adj;    // adjacency lists
    void bridge_find(int v);
public:
    Graph(int V);
    void add_edge(int v, int w);
    void bridge();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new std::list<int>[V];
}

void Graph::add_edge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::bridge_find(int u)
{
    visited[u] = true;
    disc[u] = low[u] = ++t;
    std::list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i) {
        int v = *i; // v is current adjacent of u

        if (!visited[v]) {
            parent[v] = u;
            bridge_find(v);

            low[u] = std::min(low[u], low[v]);

            if (low[v] > disc[u])
		num_b += 1;
        } else if (v != parent[u]) {
            low[u] = std::min(low[u], disc[v]);
	}
    }
}

void Graph::bridge()
{
    visited.assign(V, false);
    disc.assign(V, -1);
    low.assign(V, -1);
    parent.assign(V, -1);

    for (int i = 0; i < V; i++) {
        parent[i] = -1;
        visited[i] = false;
    }

    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            bridge_find(i);
}

int main()
{
    num_b = 0;
    t = 0;

    int n, m;
    std::cin >> n >> m;

    Graph g(n);
    for (int i = 0; i < m; i++) {
	int a, b;
	std::cin >> a >> b;
	g.add_edge(a - 1, b - 1);
    }
    g.bridge();

    std::cout << num_b << std::endl;

    return 0;
}
