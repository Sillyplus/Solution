#include <iostream>
#include <cstring>

using namespace std;

const int MN = 60;

int f[MN] = {0};

int main() {
    int n;
    cin >> n;
    memset(f, 0, sizeof(f));
    f[1] = 1;
    f[2] = 1;
    f[3] = 2;
    if (n > 3) {
        for (int i = 3; i <= n; i++)
            f[i] = f[i-1] + f[i-3] + 1;
    }
    cout << f[n] << endl;
    return 0;
}
