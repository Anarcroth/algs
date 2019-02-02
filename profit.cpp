// Task profit
// Several cells are arranged one after the other in a straight line. In `i-th` cell, a given integer `ai` is written (i=1,2, ..., N). I start from the first cell at the left end and move right. I can choose to jump into the next cell, or into the next of the next cell. Every time I entered a cell `i`, I have to pay |ai| dollars, when `ai` is negative, or to receive `ai` dollars, when `ai` is non negative. At most, how many dollars can I earn?
// Input: Integer values of N, a1, a2, ...., aN,separated by spaces.
// Output: One integer equals to the wanted profit.
// Constraints: 0 < N < 100; -100 < ai < 100 for each ai.
// Example Input
// 7 2 -1 3 -2 -1 6 -5
// Output
// 10

#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
    int N;
    std::cin >> N;
    std::vector<int> cells;
    std::vector<int> solutions;
    int input;
    for (int i = 0; i < N; i++)
    {
	std::cin >> input;
	cells.push_back(input);
    }

    cells.push_back(0);
    solutions.push_back(cells.at(0));
    solutions.push_back(cells.at(0) + cells.at(1));
    int index = 2;

    std::for_each(cells.begin() + 2, cells.end(),
		  [&solutions, &index] (int &currel) {
		      int temp = std::max(solutions.at(index - 2), solutions.at(index - 1));
		      solutions.push_back(temp + currel);
		      index += 1;
		  });

    std::cout << std::max(solutions.at(index - 1), 0) << std::endl;
    return 0;
}
