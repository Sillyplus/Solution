//
//  main.cpp
//  p1871
//
//  Created by Silly on 14-1-28.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <cmath>

const int MD = 15;

using namespace std;

int a[MD] = {0};

void sch(int x, int deep){
    if (x == 3) {
        cout << "2+2(0)";
        return;
    }
    if (x == 2) {
        cout << "2";
        return;
    }
    if (x == 1) {
        cout << "2(0)";
        return;
    }
    int t = 0;
    for (int i = MD - deep; i >= 0; i--) {
        if (a[i] <= x) {
            t = i;
            break;
        }
    }
    if (x - a[t]) {
        cout << "2(";
        sch(t, deep + 1);
        cout << ")+";
        sch(x - a[t], deep + 1);
    }else {
        cout << "2(";
        sch(t, deep + 1);
        cout << ")";
    }
}

int main(int argc, const char * argv[])
{
    int n;
    cin >> n;
    a[0] = 1;
    for (int i = 1; i < MD; i++) {
        a[i] = a[i - 1] * 2;
    }
    sch(n, 1);
    return 0;
}

