//
//  main.cpp
//  p1008
//
//  Created by Silly on 13-12-11.
//  Copyright (c) 2013年 Silly. All rights reserved.
//

#include <iostream>

typedef long long LL;
using namespace std;

const LL MD = 100003;
LL n, m;

LL km(LL a, LL b) {
    if (b == 1) {
        return a;
    }
    
}

int main(int argc, const char * argv[])
{
    cin >> n >> m;
    n %= MD;
    m %= MD;
    cout << (km(m, n) - (m * km(m-1, n-1)) % MD) % MD << endl;
    return 0;
}

