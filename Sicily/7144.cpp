//
//  main.cpp
//  s7144
//
//  Created by Silly on 13-12-11.
//  Copyright (c) 2013年 Silly. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n = 0;
int a[110] = {0};

int main(int argc, const char * argv[])
{
    cin >> n;
    while (n) {
        int k= 0, ans = 0;
        cin >> k;
        memset(a, 0, sizeof(a));
        for (int i = 0; i < k; i++) {
            cin >> a[i];
        }
        sort(a, a + k);
        for (int i = 0; i < k - 2; i++) {
            for (int j = i + 1; j < k - 1; j++) {
                for (int p = j + 1; p < k; p++) {
                    if ((a[i] + a[j] > a[p]) && (a[p] - a[j] < a[i])) {
                        ans++;
                    }
                }
            }
        }
        cout << ans << endl;
        n--;
    }
    return 0;
}

