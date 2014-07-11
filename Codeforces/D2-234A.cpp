//
//  main.cpp
//  D2-234A
//
//  Created by Silly on 14-3-5.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

char c[15];
int a[15] = {0};
bool flag[15] = {0};

int main(int argc, const char * argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c;
        memset(a, 0, sizeof(a));
        memset(flag, false, sizeof(flag));
        for (int j = 0; j < 12; j++) {
            if (c[j] == 'X') {
                a[j] += a[j - 1] + 1;
            }
        }
        /*
        for (int j = 0; j < 12; j++) {
            cout << a[j];
        }
        cout << endl;
        */
        int ans = 0;
        for (int j = 1; j <= 12; j++) {
            for (int k = 1; k <= 12; k++) {
                if ((k % j == 0) && (a[k - 1] >= j)) {
                    flag[j - 1] = true;
                    ans++;
                }
            }
        }
        cout << ans;
        for (int j = 0; j < 12; j++) {
            if (flag[j]) {
                cout << ' ' << j + 1 << 'x' << (12 / (j + 1));
            }
        }
        cout << endl;
    }
    return 0;
}

