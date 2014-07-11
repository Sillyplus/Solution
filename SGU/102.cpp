//
//  main.cpp
//  sgu102
//
//  Created by Silly on 14-1-27.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

int eular(int n){
    int rt = 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            n /= i, rt *= i - 1;
            while (n % i == 0) {
                n /= i, rt *= i;
            }
        }
    }
    if (n > 1) {
        rt *= n - 1;
    }
    return rt;
}
int main(int argc, const char * argv[])
{
    int n;
    cin >> n;
    cout << eular(n) << endl;
    return 0;
}

