/*******************************************************************************
	> File Name: 11129.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Wed Oct 28 01:25:53 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4 + 10;

int a[MAXN], tmp[MAXN];

void make(int l, int r) {
    if (r - l <= 1) {
        return;
    }
    int pos = l;
    memcpy(tmp, a, sizeof(a));
    for (int i = l; i <= r; i += 2) {
        a[pos++] = tmp[i];
    }
    for (int i = l + 1; i <= r; i += 2) {
        a[pos++] = tmp[i];
    }
    int mid = (l + r) >> 1;
    make(l, mid);
    make(mid+1, r);
}

int main(int argc, char* argv[]) {
    int n;
    while (scanf("%d", &n) == 1 && n) {
        for (int i = 0; i < n; ++i) {
            a[i] = i;
        }
        make(0, n-1);
        printf("%d:", n);
        for (int i = 0; i < n; ++i) {
            printf(" %d", a[i]);
        }
        printf("\n");
    }
    return 0;
}
