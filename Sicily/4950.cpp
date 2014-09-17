#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int a, b, c;
    while (scanf("%d%d%d", &a, &b, &c) == 3)
        cout << a*b*c << endl;
    return 0;
}
