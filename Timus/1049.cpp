/*******************************************************************************
	> File Name: 1049.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Mon Jun  8 21:59:08 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3;

int a[MAXN], b[MAXN];
map<int, int> mp;

void factor(int n) {
    int tmp, now;
    tmp = (int)((double)sqrt(n)+1);
    now = n;
    for (int i = 2; i <= tmp; ++i) if (now % i == 0) {
        while (now % i == 0) {
            mp[i]++;
            now /= i;
        }
    }
    if (now != 1) {
        mp[now]++;
    }
}

int main(int argc, char* argv[]) {
    int n, ans = 1;
    for (int i = 0; i < 10; ++i) {
        cin >> n;
        factor(n);
    }
    map<int, int>::iterator its;
    for (its = mp.begin(); its != mp.end(); ++its) {
        ans  = ans * ((*its).second + 1) % 10;
    } 
    cout << ans << endl;
    return 0;
}
