//
//  main.cpp
//  p11300
//
//  Created by Silly on 14-1-19.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MN = 1000010;
long long a[MN], c[MN], tot, m;

int main(int argc, const char * argv[])
{
    int n;
    while (scanf("%d", &n) == 1) {
        tot = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
            tot += a[i];
        }
        m = tot / n;
        c[0] = 0;
        for (int i = 1; i < n; i++) {
            c[i] = c[i - 1] + a[i] - m;
        }
        sort(c, c + n);
        long long xx = c[n / 2], ans = 0;
        for (int i = 0; i < n; i++) {
            ans += abs(xx - c[i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}

