#include <iostream>
#include <list>
#include <vector>

std::vector<bool> visited;

class graph
{
private:
    int verts;
    std::list<int> *adj;
    void dfs(int v);

public:
    graph(int _verts);
    void add_edge(int v, int w);
    int comp();
};

int graph::comp()
{
    int count = 0;

    for (int v = 0; v < verts; v++) {
	if (!visited[v]) {
	    dfs(v);
	    count++;
	}
    }
    return count;
}

void graph::dfs(int v)
{
    visited[v] = true;

    for (auto it = adj[v].begin(); it != adj[v].end(); ++it)
	if (!visited[*it])
	    dfs(*it);
}

graph::graph(int _verts)
{
    verts = _verts;
    adj = new std::list<int>[verts];
    visited.assign(verts, false);
}

void graph::add_edge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
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

    std::cout << g.comp() << std::endl;

    return 0;
}
