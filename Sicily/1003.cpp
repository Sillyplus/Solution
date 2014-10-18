#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int cnt[15];

int main() {
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++) {
        int n;
        queue<int> q[15];
        cin >> n;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < 52; i++) {
            int x;
            cin >> x;
            q[0].push(x);
        }
        int loop = 0, card = 0;
        while (card != 52) {
            for (int i = 0; i < n; i++) {
                if (!q[i].empty()) {
                    cnt[i] = (cnt[i] % 13) + 1;
                    if (cnt[i] == q[i].front()) {
                        q[i].pop();
                        if (i != n-1) {
                            q[i+1].push(cnt[i]);
                        } else {
                            card++;
                        }
                        loop = 0;
                    } else {
                        int tmp = q[i].front();
                        q[i].pop();
                        q[i].push(tmp);
                    }
                }
            }
            loop++;
            if (loop > 200)
                break;
        }
        if (card == 52) {
            cout << "Case " << k << ":";
            for (int i = 0; i < n; i++)
                cout << " " << cnt[i];
            cout << endl;
        } else {
            cout << "Case " << k << ": unwinnable" << endl;
        }
    }
    return 0;
}
