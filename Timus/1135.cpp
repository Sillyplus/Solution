/*******************************************************************************
	> File Name: 1135.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Fri Jun  5 23:41:59 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e4 + 10;

char s[MAXN];

int main(int argc, char* argv[]) {
    int n, ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%c", &s[i]);
        if (s[i] == '\n') i--;
    }
    while (true) {
        bool flag = true;
        for (int i = 0; i < n-1; i++) {
            if (s[i] == '>' && s[i+1] == '<') {
                s[i] = '<', s[i+1] = '>';
                flag = false;
                ans++;
                i++;
            }
        }
        if (flag) break;
    }
    cout << ans << endl;
    return 0;
}
