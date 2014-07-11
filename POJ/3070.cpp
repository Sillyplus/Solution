//
//  main.cpp
//  p3070
//
//  Created by Silly on 13-12-27.
//  Copyright (c) 2013年 Silly. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

typedef long long ll;
using namespace std;

const ll MD = 10000;
const ll f[2][2] = {
    {1, 1},
    {1, 0}
};

struct mx{
    ll a[2][2];
};

mx p, tp, q;

mx ml(mx a, mx b) {
    mx tmp;
    memset(tmp.a, 0, sizeof(tmp.a));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                tmp.a[i][j] += a.a[i][k] * b.a[k][j] % MD;
            }
        }
    }
    return tmp;
}

mx pw(int x) {
    if (x == 1) {
        return p;
    }
    mx tmp;
    tmp = pw(x / 2);
    tmp = ml(tmp, tmp);
    if (x % 2 == 1) {
        tmp = ml(tmp, p);
    }
    return tmp;
}

int main(int argc, const char * argv[])
{
    int n;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            p.a[i][j] = f[i][j];
        }
    }
    cin >> n;
    while (n != -1) {
        if (n == 0) {
            printf("%d\n", 0);
            scanf("%d", &n);
        }
        memset(tp.a, 0, sizeof(tp.a));
        memset(q.a, 0, sizeof(q.a));
        q = pw(n);
        printf("%lld\n", q.a[0][1] % MD);
        cin >> n;
    }
    return 0;
}

