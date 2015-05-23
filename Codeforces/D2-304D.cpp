/*******************************************************************************
	> File Name: d.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Sat May 23 00:52:16 2015
*******************************************************************************/

#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;

const int MAXN = 5000000;
typedef long long LL;

vector<int> f(MAXN+10);

int main() {
    for (LL i = 2; i <= MAXN; i++) {
        if (f[i] == 0) {
            for (LL base = i; base <= MAXN; base *= i) {
                for (LL j = base; j <= MAXN; j += base) {
                    f[j]++;
                }
            }
        }
        f[i] += f[i-1];
    }
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", f[a]-f[b]);
    }
    return 0;
}
