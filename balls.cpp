#include <iostream>
#include <vector>

int main()
{
    long long int n;
    int k;
    std::cin >> n >> k;
    std::vector<long long int> nb(n, 0);
    long long int numb;
    for (int i = 0; i < k; i++)
    {
	std::cin >> numb;
	if (numb >= 0) nb.at(numb - 1) += 1;
    }
    long long int f = 0;
    for (auto &i : nb)
    {
	if (i == 0) f += 1;
    }
    std::cout << f << std::endl;
    return 0;
}
