#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MN = 2010;

struct tk{
    int id, di;
} a[MN];

bool cmp(const tk &a, const tk &b) {
    return (a.di < b.di);
}

int main() {
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        a[i].id = i + 1;
        cin >> a[i].di;
    }
    sort(a, a+n, cmp);
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[i].di == a[i-1].di)
            ans++;
    }
    if (ans >= 2) {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++)
            cout << a[i].id << ' ';
        cout << endl;

        for (int i = 1; i < n; i++)
            if (a[i].di == a[i-1].di) {
                tk tmp;
                tmp = a[i];
                a[i] = a[i-1];
                a[i-1] = tmp;
                break;
            }
        for (int i = 0; i < n; i++)
            cout << a[i].id << ' ';
        cout << endl;

        for (int i = n-1; i > 0; i--)
            if (a[i].di == a[i-1].di) {
                tk tmp;
                tmp = a[i];
                a[i] = a[i-1];
                a[i-1] = tmp;
                break;
            }
        for (int i = 0; i < n; i++)
            cout << a[i].id << ' ';
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
