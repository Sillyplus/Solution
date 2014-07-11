#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstdlib>

using namespace std;

const int MN = 100010;

int n, m, ans;
string a[2*MN];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    for (int i = n; i < n+m; i++)
        cin >> a[i];
    sort(a, a+n+m);
    ans = 0;
    for (int i = 1; i < n+m; i++)
        if (a[i] == a[i-1]) ans++;
    cout << ans << endl;
    return 0;
}
