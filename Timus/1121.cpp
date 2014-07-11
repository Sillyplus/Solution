#include <iostream>

using namespace std;

int f[160][160] = {0};
int n, m;

int get(int x, int y) {
    if ((x >= 0) && (y >= 0) && (x < n) && (y < m)) return f[x][y];
    return 0;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> f[i][j];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (f[i][j] > 0)
                cout << "-1 ";
            else {
                int a = 0;
                for (int k = 1; k <= 5; k++) {
                    for (int l = 1; l <= k; l++) {
                        a = a | get(i-l, j+(k-l)) | get(i+l, j-(k-l))
                            | get(i-(k-l), j-l) | get(i+(k-l), j+l);
                    }
                    if (a) break;
                }
                cout << a << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}
