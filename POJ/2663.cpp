//
//  main.cpp
//  p2663
//
//  Created by Silly on 13-12-26.
//  Copyright (c) 2013年 Silly. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long  ll;

const ll  mat[8][8] = {
    {0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 0, 0, 1, 0},
};

struct ma {
    ll a[8][8];
};

ma res, tmp;

ma mm(ma x, ma y) {
    ma z;
    memset(z.a ,0 , sizeof(z.a));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                z.a[i][j] += x.a[i][k] * y.a[k][j];
            }
        }
    }
    return z;
}

ma mp(int x) {
    ma z;
    if (x == 1) {
        return res;
    }
    z = mp(x / 2);
    z = mm(z, z);
    if (x % 2 != 0) {
        z = mm(res, z);
    }
    return z;
}

int main(int argc, const char * argv[])
{
    int n;
    cin >> n;
    while (n != -1) {
        if (n == 0) {
            cout << 1 << endl;
            cin >> n;
            continue;
        }
        memset(res.a, 0, sizeof(res.a));
        memset(tmp.a, 0, sizeof(tmp.a));
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                res.a[i][j] = mat[i][j];
            }
        }
        tmp = mp(n);
        printf("%lld\n", tmp.a[7][7]);
        cin >> n;
    }
    return 0;
}

