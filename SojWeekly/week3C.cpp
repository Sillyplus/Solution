//
//  main.cpp
//  week3C
//
//  Created by Silly on 14-3-17.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

const int MN = 1010;

int f[MN] = {0};

int main(int argc, const char * argv[])
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        f[i] = i;
    }
    int x, y;
    char ch;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %c", &x, &y, &ch);
    }
    return 0;
}

