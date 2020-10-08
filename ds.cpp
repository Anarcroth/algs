#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

void pour_stack(stack<long long int> &fi, stack<long long int> &fo);

int main() {
    stack<long long int> fi; // first in stack
    stack<long long int> fo; // first out stack
    long int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int query;
        cin >> query;
        if (query == 1) {
            long long int x;
            cin >> x;
            fi.push(x);
            pour_stack(fi, fo);
        } else if (query == 2) {
            fo.pop();
            pour_stack(fo, fi);
            //fi.pop();
        } else {
            cout << fo.top() << endl;
        }
    }
    return 0;
}

void pour_stack(stack<long long int> &fi, stack<long long int> &fo) {
    stack<long long int> temp = fi;
    while (!temp.empty()) {
	//cout << "topping temp " << temp.top() << endl;
        fo.push(temp.top());
        temp.pop();
    }
}
