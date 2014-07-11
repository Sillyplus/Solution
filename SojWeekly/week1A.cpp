//
//  main.cpp
//  week1A
//
//  Created by Silly on 14-3-1.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>

using namespace std;

int sol(int x, int y) {
    if (x > y) {
        x = x % y;
    }
    if (x % y == 0) {
        return 0;
    }
    int ans = 0;
    ans = x + sol(x, y - x);
    return ans;
}

int main(int argc, const char * argv[])
{
    int n, m;
    cin >> n >> m;
    cout << sol(n, m) << endl;
    return 0;
}

