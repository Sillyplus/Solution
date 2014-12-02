#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int MAXN = 2000100;
const double EXP = 0.0000000000001;

int n;
double x, y;
int v[MAXN];

bool equal(int a, int b) {
    if (abs(a/x - b/y) < EXP)
        return true;
    else
        return false;
}

int main() {
    cin >> n >> x >> y;
    int a = 1, b = 1, md = 1;
    while (!equal(a, b)) {
        if ((a/x - b/y) < 0) {
            v[md++] = 1;
            a++;
        } else {
            v[md++] = 2;
            b++;
        }
    }
    v[md++] = 3;
    v[0] = 3;
    int k;
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        k = k % md;
        if (v[k] == 1)
            printf("Vanya\n");
        else if (v[k] == 2)
            printf("Vova\n");
        else if (v[k] == 3)
            printf("Both\n");
    }
    return 0;
}
