#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

queue<pair<int, int> > q;
int dif[10];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m;
        memset(dif, 0, sizeof(dif));
        while (!q.empty())
            q.pop();
        for (int i = 0; i < n; i++) {
            cin >> k;
            dif[k]++;
            q.push(make_pair(i, k));
        }
        int ans = 1;
        while (1) {
            pair<int, int> p;
            p = q.front();
            bool flag = false, flag1 = false;
            for (int i = p.second+1; i < 10; i++)
                if (dif[i]) {
                    flag = true;
                    break;
                }
            if (flag) {
                q.pop();
                q.push(p);
            } else {
                if (p.first == m)
                    flag1 = true;
                else
                    ans++;
                dif[p.second]--;
                q.pop();
            }
            if (flag1) break;
        }
        cout << ans << endl;
    }
    return 0;
}
