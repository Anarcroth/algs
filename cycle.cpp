#include <iostream>
#include <list>
#include <map>
#include <vector>

int no_cycle = 0;

class graph
{
private:
    int verts;
    std::list<int> *adj;
    bool check(int v, bool visited[], bool *stack);
public:
    graph(int verts);
    void add_edge(int v, int w);
    void cycle();
};

graph::graph(int _verts)
{
    verts = _verts;
    adj = new std::list<int>[verts];
}

void graph::add_edge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

bool graph::check(int v, bool visited[], bool *stack)
{
    if (!visited[v]) {
	visited[v] = true;
	stack[v] = true;
	for(auto i = adj[v].begin(); i != adj[v].end(); ++i) {
            if (!visited[*i] && check(*i, visited, stack))
                return true;
            else if (stack[*i])
                return true;
        }

    }
    stack[v] = false;
    no_cycle += 1;
    return false;
}

void graph::cycle()
{
    bool *visited = new bool[verts];
    bool *stack = new bool[verts];


    for (int i = 0; i < verts; i++) {
        stack[i] = false;
        visited[i] = false;
    }

    for (int i = 0; i < verts; i++)
	check(i, visited, stack);
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

    g.cycle();
    std::cout << no_cycle - 1 << std::endl;

    return 0;
}
