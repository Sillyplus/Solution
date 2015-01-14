/*******************************************************************************
	> File Name: 1330.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Wed Jan 14 23:48:39 2015
 ******************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 10010;

int a[MAXN];
int sum[MAXN];

int main() {
    int n;
    memset(a, 0, sizeof(a));
    memset(sum, 0, sizeof(sum));
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i-1] + a[i];
    int q, l, r;
    cin >> q;
    for (int i = 0; i < q; i++) {
        scanf("%d%d", &l, &r);
        printf("%d\n", sum[r] - sum[l-1]);
    }
    return 0;
}
