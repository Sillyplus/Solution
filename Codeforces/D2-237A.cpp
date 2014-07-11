//
//  main.cpp
//  D2-237A
//
//  Created by Silly on 14-3-19.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

const int MN = 310;

char c[MN][MN];
int n;

int main(int argc, const char * argv[])
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    char x = c[0][0];
    char y = c[0][1];
    bool a = true, b = true;
    for (int i = 0; i < n; i++) {
        if (c[i][i] != x || c[i][n-i-1] != x ) {
            a = false;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && j != (n-i-1)) {
                if (c[i][j] != y) {
                    b = false;
                }
               // cout << i << ' ' << j << endl;
            }
        }
    }
    //cout << (y == c[2][0]) << endl;
    //cout << a <<  b << endl;
    if (a && b && (x != y)) {
        cout << "YES" << endl;
    } else cout << "NO" << endl;
    return 0;
}

