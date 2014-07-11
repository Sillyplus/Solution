//
//  main.cpp
//  p3461
//
//  Created by Silly on 14-3-8.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

const int MN = 1000010;

char a[MN], b[MN];
int p[MN] = {0};
unsigned long n, m;

inline void get_p(){
    int j = -1;
    p[0] = -1;
    for (int i = 1; i < n; i++) {
        while ((j != -1) && (b[i] != b[j+1])) j = p[j];
        if (b[j+1] == b[i]) j++;
        p[i] = j;
    }
}

int kmp(){
    int j = -1;
    int ans = 0;
    get_p();
    for (int i = 0; i < m; i++) {
        while ((j != -1) && (b[j+1] != a[i])) j = p[j];
        if (b[j+1] == a[i]) j++;
        if (j == n-1) {
            ans++;
            j = p[j];
        }
    }
    return ans;
}

int main(int argc, const char * argv[])
{
    int cas;
    cin >> cas;
    while (cas--) {
        scanf("%s%s", b, a);
        n = strlen(b);
        m = strlen(a);
        printf("%d\n", kmp());
    }
    return 0;
}

