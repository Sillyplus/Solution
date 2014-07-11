//
//  main.cpp
//  week4G
//
//  Created by Silly on 14-3-22.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

char c[160][40];
int a[30];
int b[30];

int main(int argc, const char * argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        a[c[i][0] - 'a']++;
    }
    int j = 0;
    bool  fg = false;
    for (int i = 0; i < 26; i++) {
        if (a[i] >= 5) {
            b[j++] = i;
            fg = true;
        }
    }
    if (fg) {
        for (int i  = 0; i < j; i++) {
            cout << char(b[i]+'a');
        }
        cout << endl;
    } else cout << "PREDAJA\n";
    return 0;
}

