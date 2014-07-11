//
//  main.cpp
//  D2-235A
//
//  Created by Silly on 14-3-10.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

const int MN = 10000;

int main(int argc, const char * argv[])
{
    int n, x, k;
    int sum = 0;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        sum += k;
    }
    if (sum < 0) {
        sum = 0 - sum;
    }
    int ans;
    ans = (sum / x) + ((sum % x) == 0 ? 0 : 1);
    cout << ans << endl;
    return 0;
}

