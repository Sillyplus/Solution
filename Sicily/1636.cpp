//
//  main.cpp
//  p1636
//
//  Created by Silly on 14-4-2.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int main(int argc, const char * argv[])
{
    int t;
    cin >> t;
    while (t--) {
        int m, n, x, y;
        cin >> m >> n;
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            m -= x*y;
        }
        if (m >= 0) {
            cout << m << endl;
        } else cout << "Not enough\n";
    }
    return 0;
}

