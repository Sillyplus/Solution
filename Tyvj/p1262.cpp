#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;

int n, x, t;

int main() {
    cin >> n;
    while (n--) {
        scanf("%d", &x);
        x--;
        t = sqrt(x << 1);
        if ((t * (t+1)) == (x * 2))
            printf("1\n");
        else
            printf("0\n");
    }
    return 0;
}
