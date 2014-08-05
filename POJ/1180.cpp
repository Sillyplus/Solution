#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int MN = 10010;

int n, s;
int sc[MN], st[MN], f[MN], q[MN];

double grad(int x, int y) {
    return double(f[x]-f[y])/double(st[x]-st[y]);
}

int main() {
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
        cin >> st[i] >> sc[i];
    for (int i = n; i >= 1; i--) {
        st[i] += st[i+1];
        sc[i] += sc[i+1];
    }
    int h = 0, t = -1;
    q[++t] = n+1;
    for (int i = n; i > 0; i--) {
        while ((h < t) && (grad(q[h], q[h+1]) < sc[i])) h++;
        f[i] = f[q[h]]+(s+st[i]-st[q[h]])*sc[i];
        while ((h < t) && (grad(q[t-1], q[t]) > grad(q[t], i))) t--;
        q[++t] = i;
    }
    cout << f[1] << endl;
    return 0;
}
