#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
int f[1010];
queue<int> q;

int main() {
    memset(f, 0, sizeof(f));
    cin >> m >> n;
    int ans = 0, x;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (!f[x]) {
            ans++;
            if (q.size() == m) {
                int k = q.front();
                f[k] = false;
                q.pop();
            }
            q.push(x);
            f[x] = true;
        }
    }
    cout << ans << endl;
    return 0;
}
