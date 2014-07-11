//
//  main.cpp
//  D2-233C
//
//  Created by Silly on 14-3-2.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, const char * argv[])
{
    long long a, b;
    cin >> a >> b;
    if (a <= b) {
        cout << -(b-a)*(b-a) << endl;
        for (int i = 0; i < a; i++) {
            printf("xo");
        }
        for (int i = 0; i < (b - a); i++) {
            printf("x");
        }
        cout << endl;
    }
    
    return 0;
}

