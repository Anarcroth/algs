#include <iostream>

int absum(int a, int b);

int main()
{
    int ta, tb;

    std::cin >> ta >> tb;

    std::cout << absum(ta, tb) << std::endl;

    return 0;
}

int absum(int a, int b)
{
    return a + b;
}
