#include <iostream>

using namespace std;

int a[110][110] = {0};

int main() {
    int n;
    cin >> n;
    int x = 1;
    for (int i = n; i >= 1; i--) {
        int j = i, k = 1;
        while (j <= n) {
            a[k][j] = x++;
            j++; k++;
        }
    }
    for (int i = 2; i <= n; i++) {
        int j = i, k = 1;
        while (j <= n) {
            a[j][k] = x++;
            j++; k++;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << a[i][j] << ' ';
        cout << endl;
    }
    return 0;
}
