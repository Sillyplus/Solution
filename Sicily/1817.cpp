//
//  main.cpp
//  p1817
//
//  Created by Silly on 14-4-3.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

class st{
public:
    int a[110];
    double sum;
    int mx, mi;
};

st v[110];

bool comp(const st &a, const st &b) {
    if (a.sum - a.mi - a.mx < b.sum - b.mi - b.mx) {
        return true;
    }
    return false;
}

int main(int argc, const char * argv[])
{
    int n, m, k;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        v[i].mi = 101;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> k;
            v[j].a[i] = k;
            v[j].sum += k;
            v[j].mx = max(v[j].mx, k);
            v[j].mi = min(v[j].mi, k);
         }
    }
    sort(v, v + m, comp);
    double ans;
    for (int i = 0; i < m; i++) {
        ans = (v[i].sum - v[i].mx - v[i].mi) / (m * 1.0);
        printf("%.2f", ans);
    }
    return 0;
}

