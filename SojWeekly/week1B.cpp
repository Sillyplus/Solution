//
//  main.cpp
//  week1B
//
//  Created by Silly on 14-3-4.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>

using namespace std;

const int MN = 55;

int a[MN][MN] = {0};

int main(int argc, const char * argv[])
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            <#statements#>
        }
    }
    return 0;
}

