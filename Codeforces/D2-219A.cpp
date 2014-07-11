//
//  main.cpp
//  Div2-219A
//
//  Created by Silly on 13-12-13.
//  Copyright (c) 2013年 Silly. All rights reserved.
//

#include <iostream>

using namespace std;

char a[6][6];
int b[10] = {0};

int main(int argc, const char * argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i < 4; i++)
        cin >> a[i];
    for (int i = 0; i < 4 ; i++) {
        for (int j = 0; j < 4; j++) {
            int k = int(a[i][j]);
            if (k >= 49 && k <= 57) {
                b[k - 48]++;
            }
        }
    }
    for (int i = 1; i < 10; i++) {
        if (2 * n < b[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}

