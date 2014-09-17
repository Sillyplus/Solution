#include <iostream>
#include <cmath>

using namespace std;

int c[15][15];

int main() {
    for (int i = 0; i <= 10; i++)
        c[i][0] = c[i][i] = 1;
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j < i; j++)
            c[i][j] = c[i-1][j] + c[i-1][j-1];
    int n, m;
    cin >> n >> m;
    while (n != 0 || m != 0) {
        cout << c[n][m] << endl;
        cin >> n >> m;
    }
    return 0;
}
