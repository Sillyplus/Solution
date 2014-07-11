//
//  main.cpp
//  p11729
//
//  Created by Silly on 14-1-19.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct job{
    int j, b;
    bool operator < (const job& x) const {
        return j > x.j;
    }
};

int main(int argc, const char * argv[])
{
    int n, b, j, kase = 1;
    while (scanf("%d", &n) == 1 && n ) {
        vector<job> v;
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &b, &j);
            v.push_back((job){j, b});
        }
        sort(v.begin(), v.end());
        int s = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            s += v[i].b;
            ans = max(ans, s + v[i].j);
        }
        printf("Case %d: %d\n", kase++, ans);
    }
    return 0;
}

