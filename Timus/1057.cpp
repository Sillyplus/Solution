#include <iostream>

using namespace std;

int x, y, k, b;

int c[32][32] = {0};
int dgt[32] = {0};

void init() {
    c[0][0] = 1;
    for (int i = 1; i < 32; i++) {
        c[i][0] = c[i-1][0];
        for (int j = 1; j <= i; j++)
            c[i][j] += c[i-1][j-1] + c[i-1][j];
    }
}

int cal(int x) {
    int l = 0, ans = 0;
    while (x) {
        dgt[++l] = x % b;
        x /= b;
    }
    int mk = 0;
    for (int i = l; i > 0; i--) {
        if (dgt[i] > 1) {
            ans += c[i][k-mk];
            break;
        } else if (dgt[i] == 1) {
            if (i > k-mk) ans += c[i-1][k-mk];
            if (++mk > k) break;
        }
        if ((i == 1) && (mk == k)) ans++;
    }
    return ans;
}

int main() {
    cin >> x >> y >> k >> b;
    init();
    cout << cal(y) - cal(x-1) << endl;
    return 0;
}
