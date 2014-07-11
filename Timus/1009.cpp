#include <iostream>

using namespace std;

long long f[20][2] = {0}, k;

int main() {
    int n;
    cin >> n >> k;
    f[1][0] = 0;
    f[1][1] = k-1;
    for (int i = 2; i <= n; i++) {
        f[i][0] = f[i-1][1];
        f[i][1] = (f[i-1][0] + f[i-1][1]) * (k-1);
    }
    cout << f[n][0]+f[n][1] << endl;
    return 0;
}
