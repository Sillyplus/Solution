#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int n, m;

int main() {
    cin >> n >> m;
    int s, r;
    s = min(n, m);
    int flag = 0;
    if ((s % 2) == 0)
        flag = 1;
    if (flag)
        cout << "Malvika" << endl;
    else
        cout << "Akshat" << endl;
    return 0;
}
