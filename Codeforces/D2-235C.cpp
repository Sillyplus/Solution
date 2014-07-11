//
//  main.cpp
//  D2-235C
//
//  Created by Silly on 14-3-10.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, const char * argv[])
{
    int n, m;
    cin >> n >> m;
    if (n > (m+1) || (m-2) > (2*n)) {
        cout << -1 << endl;
        return 0;
    }
    if (n == m) {
        for (int i = 0; i < n; i++) {
            printf("10");
        }
        return 0;
    }
    if (n == (m+1)) {
        for (int i = 1; i < n; i++) {
            printf("01");
        }
        printf("0");
        return 0;
    }
    if (2*n == m) {
        for (int i = 0; i < n; i++) {
            printf("110");
        }
        return 0;
    }
    if (2*n >= m) {
        int k = m - n;
        for (int i = 0; i < k; i++) {
            printf("110");
        }
        for (int i = 0; i < (n - k); i++) {
            printf("10");
        }
        return 0;
    }
    for (int i = 0; i < n; i++) {
        printf("110");
    }
    for (int i = 0; i < (m - 2*n); i++) {
        printf("1");
    }
    return 0;
}

