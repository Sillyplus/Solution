//
//  main.cpp
//  week4C
//
//  Created by Silly on 14-3-22.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

const int MN = 1010;

char a[MN] ,b[MN], tmp[MN];
int n;

void change() {
    int l = 0, r = n-1;
    for (int i = 0; i < n;) {
        tmp[i++] = a[l++];
        tmp[i++] = a[r--];
    }
    for (int i = 0; i < n; i++) {
        a[i] = tmp[i];
    }
}

int main(int argc, const char * argv[])
{
    int m;
    cin >> m;
    cin >> a;
    for (int i = 0; a[i]; i++, n++) {
        b[i] = a[i];
    }
    int k;
    for (int i = 1; ; i++) {
        change();
        bool fl = false;
        for (int j = 0; j < n; j++) {
            if (a[j] != b[j]) {
                fl = true;
            }
        }
        if (!fl) {
            k = i;
            break;
        }
    }
    m = m % k;
    for (int i = 0; i < k - m; i++) {
        change();
    }
    cout << a << endl;
    return 0;
}

