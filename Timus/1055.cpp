#include <iostream>
#include <cstring>

using namespace std;

const int MN = 50010;

bool valid[MN];
int ans[MN] = {0};
int f[MN] = {0};

void getPrime(int n) {
    int tot = 0;
    memset(valid, true, sizeof(valid));
    for (int i = 2; i <= n; i++) {
        if (valid[i]) ans[++tot] = i;
        for (int j = 1; ((j <= tot) && (i*ans[j] <= n)); j++) {
            valid[i*ans[j]] = false;
            if (i % ans[j] == 0) break;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    if (m > (n/2)) m = n-m;
    getPrime(n);
    for (int i = 0; i < m; i++) {
        int t = n-i;
        if (valid[t]) {
            f[t]++;
        } else {
            int j = 0;
            while (t != 1) {
                j++;
                while (t % ans[j] == 0) {
                    f[ans[j]]++;
                    t /= ans[j];
                }
            }
        }
    }
    for (int i = 2; i <= m; i++) {
        if (valid[i]) {
            f[i]--;
        } else {
            int j = 0, t = i;
            while (t != 1) {
                j++;
                while (t % ans[j] == 0) {
                    f[ans[j]]--;
                    t /= ans[j];
                }
            }
        }
    }
    int ans = 0;
    for (int i = 2; i <= n; i++)
        if (f[i]) ans++;
    cout << ans << endl;
    return 0;
}
