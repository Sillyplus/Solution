//
//  main.cpp
//  p1597
//
//  Created by Silly on 13-11-30.
//  Copyright (c) 2013年 Silly. All rights reserved.
//

#include <iostream>

using namespace std;

long gcd(long a, long b) {
    if (a % b == 0) {
        return b;
    } else return gcd(b, a % b);
}

int main(int argc, const char * argv[])
{
    long n, m;
    cin >> n >> m;
    if (gcd(n, m) == 1) {
        cout << "YES" << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}

