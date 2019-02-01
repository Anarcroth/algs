#include <iostream>
#include <vector>

int main()
{
    int N;
    std::cin >> N;
    std::vector<int> cells;
    int input;
    for (int i = 0; i < N; i++)
    {
	std::cin >> input;
	cells.push_back(input);
    }

    int max_profit = cells.at(0);
    for (size_t i = 1; i < cells.size() - 1;)
    {
	if (cells.at(i) >= 0 && cells.at(i + 1) >= 0)
	{
	    max_profit += cells.at(i) + cells.at(i + 1);
	    i += 2;
	}
	else if (cells.at(i) < cells.at(i + 1))
	{
	    max_profit += cells.at(i + 1);
	    i += 2;
	}
	else
	{
	    max_profit += cells.at(i);
	    i += 1;
	}
	if (i == cells.size() - 1 && cells.at(i) > 0) max_profit += cells.at(i);
    }
    std::cout << max_profit << std::endl;
    return 0;
}
