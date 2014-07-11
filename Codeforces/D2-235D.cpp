//
//  main.cpp
//  D2-235D
//
//  Created by Silly on 14-3-11.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

const int MN = (1 << 18) + 3;

long long f[MN][103];
int dig[20] = {0};
char c[20];
long long fac[20];
unsigned long l;
int m;

int main(int argc, const char * argv[])
{
    cin >> c >> m;
    l = strlen(c);
    for (int i = 0; i < l; i++) {
        dig[c[i] - '0']++;
    }
    fac[0] = 1;
    for (int i = 1; i < 20; i++) {
        fac[i] = fac[i - 1] * i;
    }
    f[0][0] = 1;
    for (int s = 0; s < (1 << l); s++) {
        for (int j = 0; j < m; j++) {
            if (f[s][j]) {
                for (int i = 0; i < l; i++) {
                    if (~s & (1 << i)) {
                        if (!s && c[i] == '0') {
                            continue;
                        }
                        f[s | (1 << i)][(j * 10 + c[i] - '0') % m] += f[s][j];
                    }
                }
            }
        }
    }
    long long ans = f[(1 << l) - 1][0];
    for (int i = 0; i < 10; i++) {
        ans /= fac[dig[i]];
    }
    cout << ans << endl;
    return 0;
}

