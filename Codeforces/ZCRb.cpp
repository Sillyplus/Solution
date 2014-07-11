#include <iostream>
#include <cstdio>

using namespace std;

const int MN = 2010;

char c[MN][MN];
int ld[MN] = {0};
int rd[MN] = {0};
int ud[MN] = {0};

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (c[i][j] == 'U') {
                if ((i % 2) == 0) ud[j]++;
            } else if (c[i][j] == 'L') {
                if ((j-i) >= 0) ld[j-i]++;
            } else if (c[i][j] == 'R') {
                if ((i+j) < m) rd[i+j]++;
            }
        }
    }

    for (int i = 0; i < m; i++)
        cout << (ud[i] + ld[i] + rd[i]) << ' ';
    cout << endl;
    return 0;
}
