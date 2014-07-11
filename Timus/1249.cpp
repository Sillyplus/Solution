#include <iostream>
#include <cstdio>

using namespace std;

const int MN = 3010;

int a[MN], b[MN], c[MN];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            scanf("%d", &a[j]);
        for (int j = 0; j < m; j++)
            c[j] = a[j] + b[j];
        for (int j = 0; j < m-1; j++) {
            if ((c[j] == 1 && c[j+1] == 2) || (c[j] == 2 && c[j+1] == 1)) {
                cout << "No" << endl;
                return 0;
            }
        }
        for (int j = 0; j < m; j++)
            b[j] = a[j];
    }
    cout << "Yes" << endl;
    return 0;
}
