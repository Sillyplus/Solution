#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

const int MN = 10010;

char a[30], b[30];
int n, m, k, p;
int f[MN];

string cv(string s) {
    string ret = "";
    for (int i = 0; i < s.length(); i++) {
        for (int j = 0; j < 26; j++)
            if (s[i] == a[j]) {
                ret += b[j];
                break;
            }
    }
    return ret;
}

int find(int v) {
    return f[v] = f[v] == v ? v : find(f[v]);
}

int main() {
    cin >> a;
    cin >> b;
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
        f[i] = i;
    string s;
    for (int i = 0; i < m; i++) {
        cin >> k >> s;
        s = cv(s);
        int t = s.find("poison");
        if (t < s.length())
            f[k] = 0;
    }
    cin >> p;
    int x, y;
    for (int i = 0; i < p; i++) {
        cin >> x >> y;
        int fx = find(x), fy = find(y);
        if (fx == 0 || fy == 0) {
            f[fx] = 0;
            f[fy] = 0;
        } else {
            f[fx] = fy;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        f[i] = find(i);
        if (f[i] == 0) ans++;
    }
    cout << n-ans << endl;
    return 0;
}
