//
//  main.cpp
//  p1561
//
//  Created by Silly on 14-4-1.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 1000000;

bool valid[maxn];
int f[maxn] = {0};

void getPrime(int n, int &tot, int ans[maxn]) {
    memset(valid, true, sizeof(valid));
    for (int i = 2; i <= n; i++) {
        if (valid[i]) ans[++tot] = i;
        for (int j = 1; ((j <= tot) && (i*ans[j] <= n)); j++) {
            valid[i*ans[j]] = false;
            if (i%ans[j] == 0) break;
        }
    }
}

int main(int argc, const char * argv[])
{
    int n, tot;
    cin >> n;
    getPrime(150000, tot, f);
    cout << f[n] << endl;
    return 0;
}

