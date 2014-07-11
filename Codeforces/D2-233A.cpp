//
//  main.cpp
//  D2-233A
//
//  Created by Silly on 14-3-1.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, const char * argv[])
{
    int n, p, k;
    cin >> n >> p >> k;
    if ((p - k) > 1) {
        cout << "<< ";
    }
    int t;
    if (p - k < 1) {
        t = 1;
    } else t = p - k;
    for (int i = t; i < p; i++) {
        cout << i << " ";
    }
    cout << "(" << p << ") ";
    if (p + k > n) {
        t = n;
    } else t = p + k;
    
    //cout << p << ' ' << t << endl;
    
    for (int i = p + 1; i <= t; i++) {
        cout << i << ' ';
    }
    
    if (t < n) {
        cout << ">>\n";
    } else cout << endl;
    return 0;
}

