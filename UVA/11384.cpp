//
//  main.cpp
//  p11384
//
//  Created by Silly on 14-1-24.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

int f(int x){
    return x == 1 ? 1 : f(x / 2) + 1;
}
int main(int argc, const char * argv[])
{
    int n;
    while (scanf("%d", &n) == 1) {
        printf("%d\n", f(n));
    }
    return 0;
}

