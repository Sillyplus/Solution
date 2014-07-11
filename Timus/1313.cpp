#include <iostream>

using namespace std;

int a[110][110] = {0};

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++) {
        int j = 1, k = i;
        while (j <= n && k > 0) {
            cout << a[k][j] << ' ';
            j++; k--;
        }
    }
    for (int i = 2; i <= n; i++) {
        int j = n, k = i;
        while (k <= n) {
            cout << a[j][k] << ' ';
            j--; k++;
        }
    }
    cout << endl;
    return 0;
}
