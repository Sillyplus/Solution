/*******************************************************************************
	> File Name: 1510.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Sat Jan 10 16:37:58 2015
 ******************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n, ans, cnt = 0, k;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        if (cnt == 0) {
            ans = k;
            cnt++;
        } else if (k == ans) {
            cnt++;
        } else {
            cnt--;
        }
    }
    printf("%d\n", ans);
    return 0;
}
