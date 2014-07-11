//
//  main.cpp
//  D2-220D
//
//  Created by Silly on 13-12-18.
//  Copyright (c) 2013年 Silly. All rights reserved.
//

#include <iostream>

using namespace std;

int a[2001010] = {0};

int main(int argc, const char * argv[])
{
    int n, m, mx, le;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        scanf("%d", &a[i]);
    }
    mx = a[m];
    le = m;
    int k, t = m, h = 0, k1 = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &k);
        if (k == 1 || k == 0) {
            if (k == 1) {
                k1++;
            }
            a[++t] = k;
            le++;
        } else {
            int j;
            h = t - le + 1;
            if (le == 0 || a[h] > le) {
                continue;
            }
            if (h <= m) {
                for (j = h; (a[j] <= le) && (j <= m); j++) {}
                if (j >= h) {
                    h = h + a[j] - 1;
                }
            } else {
                if ((k1 == 0 ? false : true)) {
                    h++;
                }

            }
            le = t - h + 1;
        }
    }
    if (le == 0) {
        cout << "Poor stack!" << endl;
    } else {
        for (int i = t - le + 1; i <= t; i++) {
            printf("%d", a[i]);
        }
        cout << endl;
    }
    return 0;
}

