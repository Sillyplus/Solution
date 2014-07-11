#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const int MN = 110;

int a[MN][MN] = {0};
int sum[MN][MN] = {0};

int main() {
    int n, k;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
        }
    }
    int ans = -2147483647;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int s = 0, temp;
            for (int k = 1; k <= n; k++) {
                temp = sum[j][k] - sum[j][k-1] - sum[i-1][k] + sum[i-1][k-1];
                if (s > 0)
                    s += temp;
                else
                    s = temp;
                ans = max(ans, s);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
