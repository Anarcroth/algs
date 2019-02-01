#include <iostream>
#include <set>

int main()
{
    long long int n;
    int k;
    std::cin >> n >> k;
    std::set<long long int> nb;
    long long int numb;
    for (int i = 0; i < k; i++)
    {
	std::cin >> numb;
	if (numb >= 0) nb.insert(numb);
    }
    std::cout << n - nb.size() << std::endl;
    return 0;
}
