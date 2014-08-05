#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

const int MN = 1010;

int a[MN], b[MN], n, l;
string s;

bool check() {
    for (int i = 0; i < l; i++)
        if (a[i] != a[l-1-i]) return false;
    return true;
}

int main() {
    cin >> n >> s;
    l = s.length();
    for (int i = 0; i < l; i++)
        if (s[l-1-i] >= '0' && s[l-1-i] <= '9')
            a[i] = s[l-1-i]-'0';
        else
            a[i] = s[l-1-i]-'A'+10;
    int ans = 0;
    while (!check() && ans <= 30) {
        for (int i = 0; i < l; i++)
            b[i] = a[l-1-i];
        for (int i = 0; i < l; i++) {
            a[i] += b[i];
            a[i+1] += (a[i]/n);
            a[i] %= n;
        }
        if (a[l]) l++;
        ans++;
    }
    if (ans > 30)
        cout << "Impossible!" << endl;
    else
        cout << "STEP=" << ans << endl;
    return 0;
}
