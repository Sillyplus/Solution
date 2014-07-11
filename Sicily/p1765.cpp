//
//  main.cpp
//  p1765
//
//  Created by Silly on 14-4-3.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int a[30] = {0};

bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i*i < x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[])
{
    string s;
    while (cin >> s) {
        memset(a, 0, sizeof(a));
        for (int i = 0; i < s.length(); i++) {
            a[s[i] - 'a']++;
        }
        int mi = 1000, mx = 0, k;
        for (int i = 0; i < 26; i++) if (a[i] > 0) {
            mi = min(mi, a[i]);
            mx = max(mx, a[i]);
        }
        k = mx - mi;
        if (isPrime(k)) {
            cout << "Lucky Word" << endl;
            cout << k << endl;
        } else {
            cout << "No Answer" << endl;
            cout << 0 << endl;
        }
    }
    return 0;
}

