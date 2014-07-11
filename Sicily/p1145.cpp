//
//  main.cpp
//  p1145
//
//  Created by Silly on 14-4-1.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>

using namespace std;

const int MN = 10010;

int a[MN] = {0};

int main(int argc, const char * argv[])
{
    int l, m, x, y;
    cin >> l >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        a[x]++;
        a[y+1]--;
    }
    int ans = (a[0] == 0);
    for (int i = 1; i <= l; i++) {
        a[i] += a[i-1];
        if (a[i] == 0) ans++;
    }
    cout << ans << endl;
    return 0;
}

