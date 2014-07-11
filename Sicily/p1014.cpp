//
//  main.cpp
//  p1014
//
//  Created by Silly on 14-3-31.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[])
{
    for (int i = 1000; i < 10000; i++) {
        int k = i;
        int d = 0, e = 0, h = 0;
        while (k) {
            d += k % 10;
            k /= 10;
        }
        k = i;
        while (k) {
            e += k % 12;
            k /= 12;
        }
        k = i;
        while (k) {
            h += k % 16;
            k /= 16;
        }
        if (h == e && h == d && d == e) {
            cout << i << endl;
        }
    }
    return 0;
}

