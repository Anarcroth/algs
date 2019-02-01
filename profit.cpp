// Task profit
// Several cells are arranged one after the other in a straight line. In `i-th` cell, a given integer `ai` is written (i=1,2, ..., N). I start from the first cell at the left end and move right. I can choose to jump into the next cell, or into the next of the next cell. Every time I entered a cell `i`, I have to pay |ai| dollars, when `ai` is negative, or to receive `ai` dollars, when `ai` is non negative. At most, how many dollars can I earn?
// Input: Integer values of N, a1, a2, ...., aN,separated by spaces.
// Output: One integer equals to the wanted profit.
// Constraints: 0 < N < 100; -100 < ai < 100 for each ai.
// Example Input
// 7 2 -1 3 -2 -1 6 -5
// Output
// 10

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
	else if (cells.at(i) <= cells.at(i + 1))
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
    std::cout << std::max(max_profit, 0) << std::endl;
    return 0;
}
