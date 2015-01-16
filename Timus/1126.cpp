/*******************************************************************************
	> File Name: 1126.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Thu Jan 15 11:31:26 2015
 ******************************************************************************/

#include <cstdio>

using namespace std;

const int MAXN = 25010;

int n, m, l, r, k;
int q[MAXN] = {0}, pos[MAXN] = {0};

int main() {
    scanf("%d", &m);
    for (int i = 1; ; i++) {
        scanf("%d", &k);
        if (k == -1)
            break;
        while ((l <= r) && (i-pos[l] >= m)) l++;
        while ((r >= l) && (q[r] < k)) r--;
        q[++r] = k;
        pos[r] = i;
        if (i >= m)
            printf("%d\n", q[l]);
    }
    return 0;
}
