#include <iostream>
#include <algorithm>

using namespace std;

const int MN = 100010;
const int INF = 2147480000;

struct arr{
    int id;
    int x;
    bool operator < (const arr &b) const {
        return x < b.x;
    }
};

arr a[MN];
int b[MN];
int f[MN];
int n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x;
        a[i].id = i;
        b[i] = a[i].x;
    }
    sort(a+1, a+n+1);
    int l, r, flag;
    f[1] = 1; f[0] = 0;
    flag = 0; b[0] = -INF;
    b[n+1] = INF;
    for (int i = 2; i <= n; i++)
        if (a[i].id < a[i-1].id)
            f[i] = f[i-1]+1;
        else
            f[i] = 1;
    for (int i = n; i > 1;)
        if (f[i] > 1) {
            flag++;
            l = a[i].id;
            r = i;
            i -= f[i];
        } else {
            i--;
        }
    if (flag == 0) l = r = 1;
    if (flag == 1) {
        if ((b[l] > b[l+f[r]]) || (b[l+f[r]] < b[l-1])) flag++;
    }
    if (flag <= 1) {
        cout << "yes" << endl;
        cout << l << ' ' << l+f[r]-1 << endl;
    } else {
        cout << "no" << endl;
    }
    return 0;
}
