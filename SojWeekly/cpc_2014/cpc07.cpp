#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m;

string a[20];
int sm[50] = {0};

int main() {
    while (cin >> n >> m){
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        int ans = 10000;
        for (int i = 0; i < (1 << n); i++){
            for (int j = 0; j < m; j++) sm[j] = 0;
            int ts = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    ts++;
                    for (int k = 0; k < m; k++)
                        sm[k] += a[j][k] - '0';
                }
            }
            int flag = 1;
            for (int j = 0; j < m; j++)
                if (sm[j] > 2) flag = 0;
            if (flag) ans = min(ans, n-ts);
        }
        cout << ans << endl;
    }
    return 0;
}
