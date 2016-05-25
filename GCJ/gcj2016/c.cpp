/*******************************************************************************
	> File Name: c.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Sun Apr 10 09:17:32 2016
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 32768

int ans[MAXN];
bool valid[MAXN];

void getPrime(int n, int &tot) {
    memset(valid, true, sizeof(valid));
    for (int i = 2; i <= n; ++i) {
        if (valid[i]) {
            tot++;
            ans[tot] = i;
        } 
        for (int j = 1; (j <= tot) && (i * ans[j] <= n); ++j) {
            valid[i * ans[j]] = false;
            if (i % ans[j] == 0) break;
        }
    }
}

int main(int argc, char* argv[]) {
    int t, n, j;
    cin >> t >> n >> j;
    int tot = 0, cnt = 0;
    getPrime(pow(2, n), tot);
    int x = pow(2, n-1) + 1;
    cout << "Case #1:" << endl;
    for ( ; cnt < j && x < MAXN; x += 2) {

    }
    return 0;
}
