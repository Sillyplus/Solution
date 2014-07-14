#include <iostream>
#include <cstdio>

using namespace std;

int a, b;

int main() {
    while (scanf("%d%d", &a, &b) == 2) {
        if ((a == 2) && (b == 1))
            cout << 1 << endl;
        else if (b % a == 0)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}
