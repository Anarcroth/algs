#include <iostream>
#include <map>
#include <cmath>

int main()
{
    std::map<long int, long int> final;
    long int a = 0;
    long int b = 0;
    long int num;
    std::cin >> num;
    long int sqr = std::sqrt(num);
    if (sqr * sqr == num){
	std::cout << sqr << " " << sqr << std::endl; return 0;}
    for (long int i = 1; i <= num; i++) {
	if (num % i == 0) {
	    if (i >= a) {
		b = a;
		a = i;
		if (a * b == num) {
		    final.insert(std::make_pair(a, b));
		}
	    }
	}
    }
    long int max = 0;
    long int maxa = 0;
    long int maxb = 0;
    for (auto n : final) {
	if (n.first - n.second >= max) {
	    max = n.first - n.second;
	    maxb = n.first;
	    maxa = n.second;
	}
    }
    std::cout << maxa << " " << maxb << std::endl;
    return 0;
}
