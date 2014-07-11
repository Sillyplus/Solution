#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

const int MN = 110;

int n, m;
char c[MN][MN];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (c[i][j] == '.') {
                if (((i+j) % 2) == 0)
                    c[i][j] = 'B';
                else
                    c[i][j] = 'W';
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << c[i] << endl;
    return 0;
}
