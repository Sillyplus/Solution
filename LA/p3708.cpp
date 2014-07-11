//
//  main.cpp
//  P3708
//
//  Created by Silly on 14-1-23.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(int argc, const char * argv[])
{
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        double ans = 0.0;
        for (int i= 1; i <n; i++) {
            double pos = (double) i / n * (n + m);
            ans += fabs(pos - floor(pos + 0.5)) / (n + m);
        }
        printf("%.4f\n", ans * 10000);
    }
    return 0;
}

