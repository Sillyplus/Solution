//
//  main.cpp
//  p11462
//
//  Created by Silly on 14-1-27.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <cstring>

int x[102] = {0};

int main(int argc, const char * argv[])
{
    int n, k;
    while (scanf("%d", &n) == 1 && n) {
        memset(x, 0, sizeof(x));
        for (int i = 0; i < n; i++) {
            scanf("%d", &k);
            x[k]++;
        }
        int t = 1;
        for (int i = 0 ; i <= 100; i++) {
            if (x[i]) {
                for (int j = 0; j < x[i]; j++) {
                    if (!t) {
                        printf("%c", ' ');
                    }
                    t = 0;
                    printf("%d", i);
                }
            }
        }
        printf("\n");
    }
    return 0;
}

