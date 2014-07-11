//
//  main.cpp
//  p1875
//
//  Created by Silly on 14-2-3.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[])
{
    int n, a = 1, b = 1;
    bool flag;
    cin >> n;
    for (int i = 1; i < n; i++) {
        if ((a == 1) && (b % 2)) {
            b++;
        } else if ((a == 1) && !(b % 2)) {
            a++;
            b--;
            flag = true;
        } else if ((b == 1) && !(a % 2)) {
            a++;
        } else if ((b == 1) && (a % 2)) {
            a--;
            b++;
            flag = false;
        } else if (flag) {
            a++;
            b--;
        } else {
            a--;
            b++;
        }
    }
    cout << a << '/' << b << endl;
    return 0;
}

