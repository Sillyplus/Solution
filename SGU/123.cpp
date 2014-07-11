//
//  main.cpp
//  sgu123
//
//  Created by Silly on 14-2-25.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[])
{
    int n;
    long long ans = 1, f1 = 0, f2 = 1, t;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        ans += (f1 + f2);
        t = f2;
        f2 = f1 + f2;
        f1 = t;
    }
    cout << ans << endl;
    return 0;
}
