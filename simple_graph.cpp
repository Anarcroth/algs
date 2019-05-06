#include <iostream>
#include <map>
#include <vector>

class graph
{
public:
    int verts;
    std::vector<int> *adj;

    graph(int _verts);
    int size();
    void add_edge(int v, int w);
};

graph::graph(int _verts) : verts(_verts)
{
    adj = new std::vector<int>[verts];
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

    for (int v = 0; v < g.size(); v++) {
	std::cout << v << " :";
	for (auto w : g.adj[v])
	    std::cout << " " << w;
	std::cout << std::endl;
    }

    return 0;
}
