#include <iostream>
#include <map>
#include <vector>
#include <queue>

class graph
{
private:
    int verts;
    std::vector<int> *adj;

public:
    graph(int verts);
    void add_edge(int v, int w);
    int min_edges(int u, int v, int n);
};

graph::graph(int _verts)
{
    verts = _verts;
    adj = new std::vector<int>[verts];
}

void graph::add_edge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

int graph::min_edges(int u, int v, int n)
{
    std::vector<bool> visited(n, 0);
    std::vector<int> distance(n, 0);

    std::queue<int> Q;
    distance[u] = 0;

    Q.push(u);
    visited[u] = true;
    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();

        for (int i = 0; i < adj[x].size(); i++) {
            if (visited[adj[x][i]])
                continue;

            // update distance for i
            distance[adj[x][i]] = distance[x] + 1;
            Q.push(adj[x][i]);
            visited[adj[x][i]] = 1;
        }
    }
    return distance[v];
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<int> stack;
    graph g(n);
    for (int i = 0; i < m; i++) {
	int a, b;
	std::cin >> a >> b;
	stack.push_back(a - 1);
	stack.push_back(b - 1);
	g.add_edge(a - 1, b - 1);
    }
    int u = stack[0];
    int v = stack[stack.size() - 1];
    std::cout << g.min_edges(u, v, n) << std::endl;

    return 0;
}
