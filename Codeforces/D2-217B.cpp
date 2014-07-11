//
//  main.cpp
//  D2-217B
//
//  Created by Silly on 13-12-7.
//  Copyright (c) 2013年 Silly. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int a[101][101] = {0};
int b[101] = {0}, c[101] = {0};

int main(int argc, const char * argv[])
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        a[i][0] = k;
        for (int j =1 ; j <= k; j++) {
            int t;
            cin >> t;
            a[i][t] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        c[i] = a[i][0];
        b[i] = i;
    }
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++) {
            if (c[j] < c[i]) {
                int t;
                t = c[j];
                c[j] = c[i];
                c[i] = t;
                t = b[i];
                b[i] = b[j];
                b[j] = t;
            }
        }
    }
    c[b[1]] = 0;
    for (int i = 2; i <= n; i++) {
        int flag = 0;
        for (int j = 1; j <= i - 1; j++) {
            int sum = 0;
            for (int k = 1; k <= 100; k++) {
                if ((a[b[j]][k] == 1) && (a[b[i]][k] == 1)) {
                    sum++;
                }
            }
            if (sum == a[b[j]][0]) {
                flag = 1;
            }
        }
        c[b[i]] = flag;
    }
    for (int i = 1; i <= n; i++) {
        if (c[i] == 0) {
            cout << "YES" << endl;
        } else cout << "NO" << endl;
    }
    return 0;
}

