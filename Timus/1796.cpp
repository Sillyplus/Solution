/*******************************************************************************
	> File Name: 1796.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Sun Jan 11 23:16:42 2015
 ******************************************************************************/

#include <iostream>

using namespace std;

int a[10];
int b[] = {10, 50, 100, 500, 1000, 5000};
int p;

int main() {
    int rmd = 0, cnt = 0, mi;
    for (int i = 0; i < 6; i++) {
        cin >> a[i];
        rmd += a[i] * b[i];
    }
    cin >> p;
    int t;
    for (int i = 5; i >= 0; i--) 
        if (a[i]) t = i;
    mi = rmd - (rmd % p);
    while (mi > (rmd - b[t])) {
        cnt++;
        mi -= p;
    }
    cout << cnt << endl;
    for (int i = 1; i <= cnt; i++) {
        cout << mi/p + i << " ";
    }
    cout << endl;
    return 0;
}
