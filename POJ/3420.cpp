//
//  main.cpp
//  p3420
//
//  Created by Silly on 13-12-26.
//  Copyright (c) 2013年 Silly. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long ll;

struct mt {
    ll ma[16][16];
};

mt res, tmp;

int N, M;
int bit[4];

void init() {
    memset(res.ma, 0, sizeof(res.ma));
    memset(tmp.ma, 0, sizeof(tmp.ma));
    for (int i = 0; i < 16; i++) {
        res.ma[i][i] = 1;
    }
    for (int i = 0; i < 4; i++) {
        bit[i] = (1 << i);
    }
}

void set_mat() {
    for (int i = 0; i < 16; i++) {
        tmp.ma[i][(~i)&0xF]++;
        for (int j = 0; j < 3; j++) {
            if ( ((~i)&bit[j]&0xF) == 0 && ((~i)&bit[j+1]&0xF) == 0) {
                tmp.ma[i][((~i)|bit[j]|bit[j+1]) & 0xF]++;
            }
        }
    }
    tmp.ma[15][15]++;
}

mt mm(mt a, mt b) {
    mt c;
    memset(c.ma, 0, sizeof(c.ma));
    for (int i = 0; i < 16; i++) {
        for (int k = 0; k < 16; k++) {
            if (a.ma[i][k]) {
                for (int j = 0; j < 16; j++) {
                    c.ma[i][j] += a.ma[i][k] * b.ma[k][j];
                }
            }
        }
    }
    for (int i = 0; i < 16; i++) {
        for (int j = 0 ; j < 16; j++) {
            c.ma[i][j] %= M;
        }
    }
    return c;
}

void mat_pw() {
    for (int i = 0; i < 31; i++) {
        if (N & (1 << i))
            res = mm(res, tmp);
        tmp = mm(tmp, tmp);
    }
}

int main(int argc, const char * argv[])
{
    while (scanf("%d%d", &N, &M) && N|M) {
        init();
        set_mat();
        mat_pw();
        printf("%lld\n", res.ma[15][15]);
    }
    return 0;
}

