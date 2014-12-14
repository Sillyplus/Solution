#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 10010;

int a[] = {2, 7, 2, 3, 3, 4, 2, 5, 1, 2};

int main() {
    char x, y;
    cin >> x >> y;
    int ans = 0;
    ans = a[x-'0'] * a[y-'0'];
    cout << ans << endl;
    return 0;
}
