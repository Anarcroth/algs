#include <iostream>

int main()
{
    int num_sets;
    std::cin >> num_sets;
    long int set_size;
    long int prev_max1;
    long int prev_max2;
    for (int i = 0; i < num_sets; i++)
    {
	std::cin >> set_size;
	long long int temp;
	bool output = true;
	std::cin >> temp;
	prev_max1 = temp;
	prev_max2 = -1;
	for (int j = 1; j < set_size; j++)
	{
	    std::cin >> temp;
	    if (temp > prev_max1)
		prev_max1 = temp;
	    else if (temp > prev_max2)
		prev_max2 = temp;
	    else
	    {
		output = false;
		break;
	    }
	}
	if (output)
	    std::cout << "Yes" << std::endl;
	else
	    std::cout << "No" << std::endl;
    }
    return 0;
}
