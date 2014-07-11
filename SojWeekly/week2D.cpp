//
//  main.cpp
//  week2D
//
//  Created by Silly on 14-3-8.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int MN = 2000;

int cow[MN + 100] ={0};
int n, a, b;
double f[MN + 10][MN + 10];

int main(int argc, const char * argv[])
{
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &cow[i]);
    }
    sort(cow + 1, cow + n + 1);
    cow[0] = cow[1];
    
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j] = min(f[i-1][j-1] + a, f[i-1][j] + b * ((cow[i] - cow[i-1]) / 2.0));
        }
    }
    
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << f[i][j] << ' ';
        }
        cout << endl;
    }
    
    
    double ans = 2147483674.1;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, f[n][i]);
        cout << f[n][i] << " " ;
    }
    cout << endl;
    
    
    cout << ans << endl;
    return 0;
}

