/*******************************************************************************
	> File Name: 1204.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Tue Oct 27 20:19:15 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int x, y;

bool isPrime(int x) {
    for (int i = 2; i <= sqrt(x); ++i) {
        if (x % i == 0)
            return false;
    }
    return true;
}

void e_gcd(int a, int b) {
    if (b == 0) {
        x = 1;
        y = 0;
    } else {
        e_gcd(b, a % b);
        int t = x;
        x = y;
        y = t - a / b * y;
    }
}

int main(int argc, char* argv[]) {
    int t, n, p, q;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 2; i <=sqrt(n); ++i) {
            if (n % i == 0 && isPrime(i) && isPrime(n / i)) {
                p = i;
                q = n / i;
                break;
            }
        }
        e_gcd(p, q);
        int ans1 = p*x;
        if (ans1 < 0) ans1 += n;
        e_gcd(q, p);
        int ans2 = q*x;
        if (ans2 < 0) ans2 += n;
        if (ans1 > ans2)
            swap(ans1, ans2);
        printf("0 1 %d %d\n", ans1, ans2);
    }
    return 0;
}
