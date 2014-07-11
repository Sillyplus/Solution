//
//  main.cpp
//  sgu127
//
//  Created by Silly on 14-2-25.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>

using namespace std;

int a[13] = {0};

int main(int argc, const char * argv[])
{
    int k, n, x;
    cin >> k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a[x / 1000]++;
    }
    int ans = 2;
    for (int i = 1; i < 10; i++) {
        ans += a[i] / k;
        if (a[i] % k) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

