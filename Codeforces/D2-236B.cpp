//
//  main.cpp
//  D2-236B
//
//  Created by Silly on 14-3-19.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const int MN = 1010;

int a[MN] = {0};
int f[MN] = {0};
int n, k;

int main(int argc, const char * argv[])
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            f[i] += (a[i] - a[j]) == (i - j) * k;
        }
    }
    //for (int i = 1; i <= n; i++) cout << f[i][0] << endl;
    //cout << endl;
    int ans = 0;
    int hold = 1;
    for (int i = 1; i <= n; i++) {
        if ((i - 1) * k < a[i] && (ans < f[i])) {
            ans = f[i];
            hold = i;
        }
    }
   // cout << ans << endl;
    ans = n - ans;
    cout << ans << endl;
    if (ans) {
        int st = a[hold] - hold * k;
        for (int i = 1; i <= n; i++) {
            st += k;
            if (a[i] != st) {
                if (a[i] < st) {
                    cout << "+ " << i << " " << st - a[i] << endl;
                } else {
                    cout << "- " << i << " " << a[i] - st << endl;
                }
            }
        }
    }
    return 0;
}

