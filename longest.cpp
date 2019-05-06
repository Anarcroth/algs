#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

std::vector<int> visited;
std::map<int, int> vert;
std::vector<int> max;
int globali = 0;
int longest = 0;

void dfs(int i)
{
    //std::cout << "currently at " << i << std::endl;
    if (i > visited.size()) return;
    if (visited[i] == 0) {
	visited[i] = 1;
	longest += 1;
	auto searchI = vert.find(i);
	if (searchI != vert.end()) {
	    dfs(searchI->second);
	} else {
	    max.push_back(longest);
	    longest = 0;
	    int gotodat = 0;
	    for (int j = 1; j <= visited.size(); j++) {
	    	if (visited[j] == 0) {
	     	    gotodat = j;
		    break;
		}
	    }
	    //std::cout << "going to " << gotodat << std::endl;
	    dfs(gotodat);
	}
    }
    dfs(i + 1);
}


int main()
{
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < m; i++) {
	int a, b;
	std::cin >> a >> b;
	vert.insert(std::make_pair(a, b));
    }

    for (int i = 0; i <= n; i++) {
	visited.push_back(0);
    }

    dfs(1);
    std::cout << *max_element(max.begin(), max.end()) << std::endl;
    //std::cout << longest << std::endl;

    return 0;
}
