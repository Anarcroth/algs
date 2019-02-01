#include <iostream>

int sum(int lower_b, int upper_b);

int main()
{
    int ta, tb;

    std::cin >> ta >> tb;

    std::cout << sum(ta, tb) << std::endl;

    return 0;
}

int sum(int lower_b, int upper_b)
{
    int sum = 0;
    if (lower_b > upper_b) std::swap(lower_b, upper_b);
    for (int i = lower_b; i <= upper_b; i++)
    {
	sum += i;
    }
    return sum;
}
