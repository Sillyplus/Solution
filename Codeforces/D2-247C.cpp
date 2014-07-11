#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

const int MN = 100010;
const int mod = 1e9 + 7;

int n, k, d;
int f1[MN] = {0};
int f2[MN] = {0};

int main() {
    cin >> n >> k >> d;
    f1[0] = f2[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if ((i-j) >= 0)
                f1[i] = (f1[i] + f1[i-j]) % mod;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < d; j++) {
            if ((i-j) >= 0)
                f2[i] = (f2[i] + f2[i-j]) % mod;
        }
    }
    int ans = (f1[n]-f2[n] + mod) % mod;
    //at first WA with ans = (f1[n] - f2[n]) % mod; TAT
    cout << ans << endl;
    return 0;
}
