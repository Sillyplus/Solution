/*******************************************************************************
	> File Name: a.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Tue Dec 30 23:00:07 2014
 ******************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1e5;

int a[MAXN];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int k = 1;
    bool flag = false;
    while (k <= m && k <= n) {
        if (k == m) {
            flag = true;
            break;
        } else k = k + a[k];
    }
    if (flag)
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;
    return 0;
}
