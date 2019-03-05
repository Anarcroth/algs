#include <iostream>
#include <vector>

int main()
{
    int setsize;
    std::cin >> setsize;
    std::vector<int> set;
    std::vector<int> answers(2000002, 0);
    int input;
    int neg_sum = 0;
    int pos_sum = 0;
    for (int i = 0; i < setsize; i++)
    {
	std::cin >> input;
	if (input < 0) neg_sum += input;
	else pos_sum += input;
	set.push_back(input);
    }

    neg_sum = -(neg_sum);
    int bothsums = (neg_sum) + pos_sum;

    answers.at(set[0] + (neg_sum)) = 1;
    for (int i = 1; i < setsize; i++)
    {
	int z = (neg_sum) - set[i];
	if (set[i] < 0)
	{
	    for (int j = -neg_sum + set[i]; j <= bothsums; j++)
	    {
		if (answers.at(j + z))
		    answers.at(j + (neg_sum)) = 1;
	    }
	}

	if (set[i] > 0)
	{
	    for(int j = bothsums; j >= -neg_sum + set[i]; j--)
	    {
		if (answers.at(j + z))
		    answers.at(j + (neg_sum)) = 1;
	    }
	}

	answers.at(set[i] + (neg_sum)) = 1;
    }

    for (int j = (neg_sum) + 1; j <= bothsums + 1; j++)
    {
	if (answers.at(j) == 0)
	{
	    std::cout << j - neg_sum << std::endl;
	    return 0;
	}
    }
}
