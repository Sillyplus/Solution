//
//  main.cpp
//  p1691
//
//  Created by Silly on 14-4-2.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int MN = 1200;

int a[MN] = {0};

int main(int argc, const char * argv[])
{
    for (int i = 1; i <= 1024; i++) {
        for (int j = 1; j <= i; j++) {
            if (i%j == 0) {
                a[i] += j;
            }
        }
        if (! ((a[i] - 2*i) > 0)) {
            a[i] = -1;
        } else a[i] -= 2*i;
    }
    int t, x, y;
    cin >> t;
    while (t--) {
        cin >> x >> y;
        int ans = -1;
        for (int i = x; i <= y; i++) {
            ans = max(a[i], ans);
        }
        cout << ans << endl;
    }
    return 0;
}

