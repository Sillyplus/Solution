//
//  main.cpp
//  sgu297
//
//  Created by Silly on 14-3-6.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, const char * argv[])
{
    int n, m, k, ans = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        scanf("%d", &k);
        ans += k;
    }
    cout << ans % n << endl;
    return 0;
}

