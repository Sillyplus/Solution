#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int MN = 1010;

char c[MN];
int a[30];
int k;

int main() {
    cin >> c;
    cin >> k;
    int mx = 0;
    for (int i = 0; i < 26; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    int ans = 0;
    int i;
    for (i = 0; c[i]; i++)
        ans += (a[c[i]-'a'] * (i+1));
    for (int j = 1; j <= k; j++)
        ans += ((j+i) * mx);
    cout << ans << endl;
    return 0;
}
