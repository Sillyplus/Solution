//
//  main.cpp
//  D2-236A
//
//  Created by Silly on 14-3-19.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[])
{
    int k, a, b, v;
    cin >> k >> a >> b >> v;
    int ans = 0;
    int sum = 0;
    while (sum < a) {
        int t = 1;
        ans++;
        sum += v;
        while (sum < a && b && t < k) {
            sum += v;
            b--;
            t++;
        }
    }
    cout << ans << endl;
    return 0;
}

