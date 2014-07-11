#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

const int MN = 1000000;

char str[5];
double d;
int f[MN+10] = {0};

inline int lowbit(int x) {
    return (x & -x);
}

void add(int x, int value) {
    for (int i = x; i <= MN; i += lowbit(i))
        f[i] += value;
}

int get(int x) {
    int sum = 0;
    for (int i = x; i; i -= lowbit(i))
        sum += f[i];
    return sum;
}

int main() {
    cin >> str;
    double ans = 0;
    int k;
    while (str[0] != 'Q') {
        if (str[0] == 'B') {
            scanf("%lf", &d);
            add(int(d*100 + 0.5), 1);
        } else if (str[0] == 'D') {
            scanf("%lf", &d);
            add(int(d*100 + 0.5), -1);
        } else if (str[0] == 'S') {
            scanf("%lf%d", &d, &k);
            int t = int(d*100 + 0.5);
            int ts = get(MN) - get(t-1);
            ans += min(k, ts);
        }
        scanf("%s", str);
    }
    ans /= 100.0;
    printf("%.2f\n", ans);
    return 0;
}
