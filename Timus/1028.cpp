#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

const int MN = 32001;

struct pt{
    int x, y;
};

pt a[MN/2];
int level[MN/2];
int t[MN+10];

bool comp(const pt &a, const pt &b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

inline int lowbit(int x) {
    return (x & -x);
}

void add(int x, int value) {
    for (int i = x; i <= MN; i += lowbit(i))
        t[i] += value;
}

int get(int x) {
    int sum = 0;
    for (int i = x; i; i -= lowbit(i))
        sum += t[i];
    return sum;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i].x, &a[i].y);
    }
    sort(a, a+n, comp);
    for (int i = 0; i < n; i++) {
        int k = a[i].y+1;
        level[get(k)]++;
        add(k, 1);
    }
    for (int i = 0; i < n; i++)
        printf("%d\n", level[i]);
    return 0;
}
