//
//  main.cpp
//  p1795
//
//  Created by Silly on 14-4-3.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, const char * argv[])
{
    int t;
    cin >> t;
    while (t--) {
        int n, x, y, ans = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            if (((x-170)*(x-170)+(y-30)*(y-30)) < 25) {
                ans += 3;
            } else if (((x-100)*(x-100)+(y-30)*(y-30)) < 100 && ((x-170)*(x-170)+(y-30)*(y-30)) > 25) {
                ans += 2;
            } else if (((x-30)*(x-30)+(y-30)*(y-30)) < 400 && ((x-100)*(x-100)+(y-30)*(y-30)) > 100) {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

