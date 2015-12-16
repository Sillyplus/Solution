/*******************************************************************************
	> File Name: 1346.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Wed Dec 16 22:54:29 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
int s[MAXN], f[MAXN][2];

int main(int argc, char* argv[]) {
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; ++i) {
        cin >> s[i];
    }
    f[a][0] = f[a][1] = 1;
    for (int i = a + 1; i <= b; ++i) {
        if (s[i] > s[i-1]) {
            f[i][0] = min(f[i-1][0], f[i-1][1]) + 1;
        } else {
            f[i][0] = f[i-1][0];
        }
        if (s[i] < s[i-1]) {
            f[i][1] = min(f[i-1][0], f[i-1][1]) + 1;
        } else {
            f[i][1] = f[i-1][1];
        }
    }
    cout << min(f[b][0], f[b][1]) << endl;
    return 0;
}
