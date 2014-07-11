//
//  main.cpp
//  sgu115
//
//  Created by Silly on 14-2-24.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>

using namespace std;

int a[13] = {0, 31, 28, 31, 30, 31 , 30, 31, 31, 30, 31, 30, 31};

int main(int argc, const char * argv[])
{
    int n, m;
    cin >> n >> m;
    if (n > a[m] || n < 1) {
        cout << "Impossible" << endl;
        return 0;
    }
    int k = 0;
    for (int i = 0; i < m; i++) {
        k += a[i];
    }
    k += n;
    k %= 7;
    if (k == 0) {
        k = 7;
    }
    cout << k << endl;
    return 0;
}

