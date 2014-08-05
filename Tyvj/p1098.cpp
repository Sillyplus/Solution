#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

const int MN = 5010;

int n, s;
int st[MN], sc[MN], f[MN];

int main() {
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> st[i] >> sc[i];
    }
    for (int i = n; i >= 1; i--) {
        st[i] += st[i+1];
        sc[i] += sc[i+1];
    }
    memset(f, 63, sizeof(f));
    f[n+1] = 0;
    for (int i = n; i >= 1; i--) {
        for (int j = i+1; j <= n+1; j++) {
            f[i] = min(f[i], f[j]+(s+st[i]-st[j])*sc[i]);
        }
    }
    cout << f[1] << endl;
    return 0;
}
