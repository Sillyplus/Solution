#include <iostream>
#include <cstdio>

using namespace std;

const int MN = 1200;

int k, n;
long long f[MN];
long long a[20];
int main() {
    while (scanf("%d%d", &k, &n) == 2) {
        a[0] = 1;
        for (int i = 1; i <= 10; i++)
            a[i] = a[i-1] * k;
        for (int i = 1; i <= 1000; i++) {
            int tn, cnt;
            long long ans = 0;
            tn = i;
            cnt = 0;
            while (tn) {
                int tmp = tn % 2;
                ans += tmp * a[cnt++];
                tn /= 2;
            }
            f[i] = ans;
        }
        cout << f[n] << endl;
    }
    return 0;
}
