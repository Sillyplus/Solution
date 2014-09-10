//
//  main.cpp
//  p1623
//
//  Created by Silly on 14-4-2.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>

using namespace std;

int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
}

int main(int argc, const char * argv[])
{
    int t, a, b, k = 0;
    cin >> t;
    while (++k <= t) {
        cin >> a >> b;
        cout << k << ' ' << a*b / gcd(a, b) << ' ' << gcd(a, b) << endl;
    }
    return 0;
}

