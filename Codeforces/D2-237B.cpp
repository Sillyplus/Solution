//
//  main.cpp
//  D2-237B
//
//  Created by Silly on 14-3-20.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(int argc, const char * argv[])
{
    double a, d;
    cin >> a >> d;
    int n;
    cin >> n;
    double tmp = 0, x, y;
    for (int i = 0; i < n; i++) {
        tmp += d;
        tmp = fmod(tmp, 4*a);
        if (tmp <= a) {
            x = tmp;
            y = 0;
        } else if (tmp <= 2*a) {
            x = a;
            y = tmp - a;
        } else if (tmp <= 3*a) {
            x = 3*a - tmp;
            y = a;
        } else {
            x = 0;
            y = 4*a - tmp;
        }
        printf("%.10f %.10f\n", x, y);
    }
    return 0;
}

