//
//  main.cpp
//  p1154
//
//  Created by Silly on 14-3-31.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int a[1100] = {0};

int main(int argc, const char * argv[])
{
    int t;
    cin >> t;
    int n;
    while (t--) {
        cin >> n;
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        for (int i = 0; i < n; i++) {
            printf("%d\n", a[i]);
        }
    }
    return 0;
}

