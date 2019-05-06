#include <iostream>
#include <vector>

class graph
{
public:
    int verts;
    std::vector<int> *adj;
    std::vector<bool> visited;

    graph(int _verts);
    int size();
    void add_edge(int v, int w);

    void dfs(int i);
};

graph::graph(int _verts) : verts(_verts)
{
    adj = new std::vector<int>[verts];
    visited.assign(verts, false);
}

int graph::size()
{
    return verts;
}

void graph::add_edge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void graph::dfs(int i)
{
    visited[i] = true;
    std::cout << i << " ";
    for (auto it = adj[i].begin(); it != adj[i].end(); ++it)
	if (!visited[*it])
	    dfs(*it);
}

int main()
{
    int n, m;
    std::cin >> n >> m;

    graph g(n);
    for (int i = 0; i < m; i++) {
	int a, b;
	std::cin >> a >> b;
	g.add_edge(a - 1, b - 1);
    }

    g.dfs(2);

    return 0;
}
