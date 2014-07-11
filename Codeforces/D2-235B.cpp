//
//  main.cpp
//  D2-235B
//
//  Created by Silly on 14-3-11.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

const int MN = 4010;

int a[MN] = {0};

int main(int argc, const char * argv[])
{
    int n, k, mx = 0;
    cin >> n >> k;
    int t, x, y;
    for (int i = 0; i < k; i++) {
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d%d", &x, &y);
            a[x] = 1;
            a[y] = 1;
            mx += 2;
        } else {
            scanf("%d", &x);
            a[x] = 1;
            mx += 1;
        }
    }
    int tmp = 0;
    int mi = 0;
    a[n] = 1;
    for (int i = 1; i <= n; i++) {
        if (!a[i]) {
            tmp++;
        } else {
            mi = mi + tmp / 2 + (tmp % 2 == 0 ? 0 : 1);
            tmp = 0;
        }
    }
    mx = n - mx - 1;
    if (mi == 0 && mx == (n - 1)) {
        mi = n / 2;
    }
    cout << mi << " " << mx << endl;
    return 0;
}

