#include <iostream>
#include <cmath>

using namespace std;

int a[10];
int f[110];

int main() {
    int n, k;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> k;
        a[k]++;
    }
    for (int i = 1; i <= a[1]; i++)
        f[i] = i;
    for (int i = 1; i <= a[2]; i++)
        f[a[1]+i] = i;
    for (int i = 1; i <= a[3]; i++)
        f[a[1]+a[2]+i] = i;
    double ans = 1;
    for (int i = 1; i <= n; i++) {
        ans *= double(i);
        ans /= double(f[i]);
    }
    if (ans >= 6)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
