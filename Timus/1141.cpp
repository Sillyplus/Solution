/*******************************************************************************
	> File Name: 1141.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Tue Oct 27 19:51:37 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int e, n, c, m, x, y;

void e_gcd(int a, int b) {
    if (b == 0) {
        x = 1;
        y = 0;
    } else {
        e_gcd(b, a % b);
        int t = x;
        x = y;
        y = t - (a / b) * y;
    }
}

int main(int argc, char* argv[]) {
    int t;
    cin >> t;
    while (t--) {
        cin >> e >> n >> c;
        int p, q;
        for (p = 3; p < sqrt(n); ++p) {
            if (n % p == 0) {
                break;
            }
        }
        q = n / p;
        e_gcd(e, (p-1)*(q-1));
        m = 1;
        if (x < 0) {
            x += (p-1)*(q-1);
        }
        for (int i = 1; i <= x; ++i) {
            m = m * c % n;
        }
        cout << m << endl;
    }
    return 0;
}
