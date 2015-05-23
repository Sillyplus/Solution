/*******************************************************************************
	> File Name: 1134.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Thu May 21 08:46:16 2015
*******************************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1010;

int a[MAXN], f[MAXN] = {0};

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) 
        cin >> a[i];
    sort(a, a+m);
    bool flag = true;
    f[0] = 1;
    if (a[0] == 0) {
        f[0]++;
        f[1]++;
    } else {
        f[a[0]-1]++;
        f[a[0]]++;
    }
    for (int i = 1; i < m; i++) {
        if (f[a[i]] < 2 && f[a[i]-1] < 2) {
            f[a[i]]++;
            f[a[i]-1]++;
        } else if (f[a[i]] < 2 && f[a[i]+1] < 2) {
            f[a[i]]++;
            f[a[i]+1]++;
        } else {
            flag = false;
            break;
        }
    }
    if (f[n+1]) flag = false;
    if (flag)
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;
    return 0;
}
