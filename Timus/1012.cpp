#include <iostream>

using namespace std;

int f1[50], f2[50], f3[50];

int main() {
    int n, k;
    cin >> n >> k;
    f1[0] = k-1;
    f2[0] = k * (k-1);
    for (int i = 3; i <= n; i++) {
        for (int j = 0; j < 50; j++)
            f3[j] = 0;
        for (int j = 0; j < 49; j++) {
            f3[j] += (f1[j] + f2[j]) * (k-1);
            f3[j+1] = f3[j] / 10000;
            f3[j] %= 10000;
        }

        for (int j = 0; j < 50; j++)
            f1[j] = f2[j];
        for (int j = 0; j < 50; j++)
            f2[j] = f3[j];
    }
    int x = 49;
    while (!f2[x]) x--;
    cout << f2[x--];
    for (int i = x; i >= 0; i--) {
        if (f2[i] < 1000) cout << '0';
        if (f2[i] < 100) cout << '0';
        if (f2[i] < 10) cout << '0';
        cout << f2[i];
    }
    cout << endl;
    return 0;
}
