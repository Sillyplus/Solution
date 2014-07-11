//
//  main.cpp
//  week3A
//
//  Created by Silly on 14-3-15.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MN = 100100;

struct cow{
    int x;
    int y;
};

cow a[2 * MN];

bool comp(const cow &a, const cow &b){
    if (a.x != b.x) {
        return a.x < b.x;
    } else return a.y < b.y;
}

int main(int argc, const char * argv[])
{
    int n;
    int k; char c;
    int now = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d %c", &k, &c);
        if (c == 'R') {
            a[i].x = now;
            a[i].y = 1;
            now += k;
            a[n+i].x = now;
            a[n+i].y = -1;
        } else {
            a[i].x = now;
            a[i].y = -1;
            now -= k;
            a[n+i].x = now;
            a[n+i].y = 1;
        }
    }
    sort(a, a+(2*n), comp);
    
    /*
    for (int i = 0; i < 2*n; i++) {
        cout << a[i].x << ' ' << a[i].y << endl;
    }
     */
    int ans = 0;
    now = 1;
    for (int i = 1; i < 2 * n; i++) {
        
        if (a[i].x != a[i-1].x) {
            if (now >= 2) {
                ans += (a[i].x - a[i-1].x);
               // cout << i << ' ' << ans << endl;
            }
        }
        now += a[i].y;
    }
    cout << ans << endl;
    return 0;
}

