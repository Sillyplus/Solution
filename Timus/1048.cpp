#include <iostream>
#include <cstdio>

using namespace std;

const int MN = 1000010;

int c[MN];

int main() {
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        c[i] = a + b;
    }
    for (int i = n-1; i > 0; i--) {
        c[i-1] += c[i] / 10;
        c[i] %= 10;
    }
    for (int i = 0; i < n; i++)
        printf("%d", c[i]);
    cout << endl;
    return 0;
}
