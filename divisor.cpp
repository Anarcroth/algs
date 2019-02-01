#include <iostream>
#include <vector>

void divs(std::vector<int> &set, int m);

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<int> set;
    for (int i = 0; i < n; i++)
    {
	int temp;
	std::cin >> temp;
	set.push_back(temp);
    }

    divs(set, m);

    return 0;
}

void divs(std::vector<int> &set, int m)
{
    std::vector<int> final;
    int total = 0;
    for (auto &s : set)
    {
	for (int i = 2; i < s; i++)
	{
	    if (s % i == 0)
	    {
		total += 1;
	    }
	}
	final.push_back(total);
	total = 0;
    }

    int res = 0;
    for (int i = 0; i < final.size(); i++)
    {
	if (final[i] == m) res += 1;
    }

    std::cout << res << std::endl;
}
