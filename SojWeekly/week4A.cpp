//
//  main.cpp
//  week4A
//
//  Created by Silly on 14-3-22.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;

int main(int argc, const char * argv[])
{
    int t;
    char c;
    int tt = 0;
    cin >> m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d %c", &t, &c);
        tt += t;
        if (tt >= 210) {
            cout << m << endl;
            return 0;
        }
        if (c == 'T') {
            m = (m % 8) + 1;
        }
    }
    cout << m << endl;
    return 0;
}

