//
//  main.cpp
//  p2035
//
//  Created by Silly on 14-1-29.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

const int MN = 1010;
bool map[MN][MN] = {0};

int main(int argc, const char * argv[])
{
    int n, m, x, y;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &x, &y);
        map[x][y] = true;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (map[i][k] && map[k][j]) {
                    map[i][j] = true;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (map[i][i]) {
            printf("T\n");
        } else printf("F\n");
    }
    return 0;
}

