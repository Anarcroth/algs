#include <iostream>

int main()
{
    long long int a;
    long long int b;
    long long int c;
    std::cin >> a >> b >> c;
    long long int counter = 0;
    if (c >= a)
	a = c;

    if (b < c) {
	std::cout << 0 << std::endl;
	return 0;
    }

    for (auto i = a; i <= b; i++) {
	if (i % c == 0) {
	    counter += 1;
	    i += c - 1;
	}
    }
    std::cout << counter << std::endl;
    return 0;
}
