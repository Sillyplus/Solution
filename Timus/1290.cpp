#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MN = 25010;

int a[MN] = {0};

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a+n);
    for (int i = n-1; i >= 0; i--) {
        printf("%d\n", a[i]);
    }
    return 0;
}
