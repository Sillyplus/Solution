//
//  main.cpp
//  p1219
//
//  Created by Silly on 14-1-28.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int MN = 101;

int a[MN][MN] = {0};
int s[MN][MN] = {0};

int main(int argc, const char * argv[])
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    }
    int mx = -1000001000, t = 0;
    int mn = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            t = max(i, j);
            t = n - t;
            for (int k = 0; k <= t; k++) {
                int x;
                x = s[i+k][j+k] - s[i-1][j+k] - s[i+k][j-1] + s[i-1][j-1];
                mx = max(mx, x);
                mn = min(mn, x);
            }
        }
    }
    cout << mx << endl;
    cout << abs(mn) << endl;
    return 0;
}

