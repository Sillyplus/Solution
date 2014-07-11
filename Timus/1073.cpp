#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

const int MN = 250;

int f[MN*MN], c[MN];

int main() {
    for (int i = 0; i < MN; i++)
        c[i] = i*i;
    memset(f, 0x3f, sizeof(f));
    //memset(f, 0, sizeof(f));
    int n;
    cin >> n;
    int k = sqrt(n) + 1;
    f[0] = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = c[i]; j <= n; j++)
            if (j-c[i] >= 0)
                f[j] = min(f[j], f[j-c[i]]+1);
    }

    cout << f[n] << endl;
    return 0;
}
