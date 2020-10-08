#include <vector>
#include <iostream>

class point
{
public:
    int x;
    int y;
};

bool is_side_smaller(int a, int b, int x, int y)
{
    // compare a with x and b with y
    if (a < 0) {
	if
    } else {

    }
    return true;
}

bool are_crossing()
{
    return false;
}

void triang()
{

}

int main()
{
    std::vector<std::vector<point>> triangles;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
	int p1x, p1y, p2x, p2y, p3x, p3y;
	std::cin >> p1x >> p1y >> p2x >> p2y >> p3x >> p3y;
	point p1, p2, p3;
	p1.x = p1x; p1.y = p1y;
	p2.x = p2x; p2.y = p2y;
	p3.x = p3x; p3.y = p3y;
	std::vector<point> tr;
	tr.push_back(p1);
	tr.push_back(p2);
	tr.push_back(p3);
	triangles.push_back(tr);
    }
    return 0;
}
