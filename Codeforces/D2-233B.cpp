//
//  main.cpp
//  D2-233B
//
//  Created by Silly on 14-3-2.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>

using namespace std;

const int MN = 52;

long long f[MN];
char a[MN];

long long sol(int x){
    if (x == 0) {
        if (a[x] == 'R') {
            return 0;
        } else return 1;
    }
    if (a[x] == 'R') {
        return sol(x - 1);
    }
    long long ans;
    ans = sol(x - 1) + f[x - 1] + 1;
    return ans;
}

int main(int argc, const char * argv[])
{
    int n;
    cin >> n;
    cin >> a;
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = 2 * f[i - 1] + 1;
    }
    cout << sol(n - 1) << endl;
    return 0;
}

