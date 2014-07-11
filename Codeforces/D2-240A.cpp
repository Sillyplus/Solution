#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

const int MN = 10010;

int a[MN] = {0};

int main() {
    int n, m;
    int k;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> k;
        for (int j = k; j <= n; j++) {
            if (a[j] == 0) a[j] = k;
        }
    }
    cout << a[1];
    for (int i = 2; i <= n; i++)
    cout << " " << a[i];
    return 0;
}
