/*******************************************************************************
	> File Name: 1343.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Tue Oct 27 19:26:18 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int n;

bool isPrime(LL x) {
    for (LL i = 2; i <= (LL)sqrt(x); ++i) {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main(int argc, char* argv[]) {
    srand(0);
    cin >> n;
    LL k = 0;
    if (n) {
        cin >> k;
    }
    LL x;
    do {
        x = k;
        for (int i = n+1; i <= 12; ++i) {
            x = x * 10 + (LL)((rand() & 31) % 10);
        }
    } while (!isPrime(x));
    printf("%012lld\n", x);
    return 0;
}
