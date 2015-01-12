/*******************************************************************************
	> File Name: 1642.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Mon Jan 12 22:33:39 2015
 ******************************************************************************/

#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 2014;

bool f[MAXN];

int main() {
    int n, x, k;
    memset(f, false, sizeof(f));
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> k;
        f[k + 1000] = true;
    }
    int l, r, t;
    t = l = r = 1000;
    x += 1000;
    while (!f[r] && r < MAXN) r++;
    while (!f[l] && l >= 0) l--;
    if (r < x || l > x) {
        cout << "Impossible" << endl;
    } else {
        if (x > 1000) {
            r = x - 1000;
            l = (x - l) + (1000 - l);
        } else {
            l = 1000 - x;
            r = (r - x) + (r - 1000);
        }
        cout << r << " " << l << endl;
    }
    return 0;
}
