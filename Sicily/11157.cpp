#include <iostream>

using namespace std;

char c[30][30];
char p[15][15];

int n, m, u, l, r, d;

int main() {
    cin >> n >> m;
    cin >> u >> l >> r >> d;
    for (int i = 0; i < n; i++)
        cin >> p[i];
    for (int i = 0; i < (n+u+d); i++)
        for (int j = 0; j < (m+l+r); j++)
            if ((i + j) % 2 == 0)
                c[i][j] = '#';
            else
                c[i][j] = '.';
    for (int i = u; i < (u+n); i++)
        for (int j = l; j < (l+m); j++)
            c[i][j] = p[i-u][j-l];
    for (int i = 0; i < (n+u+d); i++)
        cout << c[i] << endl;
    return 0;
}
