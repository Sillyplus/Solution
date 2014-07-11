//
//  main.cpp
//  Div2-219C
//
//  Created by Silly on 13-12-13.
//  Copyright (c) 2013年 Silly. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;

const int MN = 500000;

int a[MN + 10] = {0};
int n , mid, k, ans;

int main(int argc, const char * argv[])
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    ans = n;
    k = n - 1;
    mid = n / 2 - 1;
    for (int i = mid; i >= 0; i--) {
        if ((a[k] / 2) >= a[i]) {
            ans = ans - 1;
            k--;
        }
    }
    cout << ans << endl;
    return 0;
}

