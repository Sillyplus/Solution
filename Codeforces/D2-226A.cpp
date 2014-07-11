//
//  main.cpp
//  D2-226A
//
//  Created by Silly on 14-1-25.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, const char * argv[])
{
    int n, c, ans, k1, k2;
    cin >> n >> c;
    cin >> k1;
    ans = -10000101;
    for (int i = 1; i < n; i++) {
        cin >> k2;
        ans = max(ans, k1 - (k2 + c));
        k1 = k2;
    }
    if (ans < 0) {
        cout << 0 << endl;
    } else cout << ans << endl;
    return 0;
}

