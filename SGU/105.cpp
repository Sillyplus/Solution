//
//  main.cpp
//  sgu105
//
//  Created by Silly on 14-2-24.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[])
{
    int n;
    cin >> n;
    int k;
    k = n / 3;
    if (n % 3 != 0) {
        k++;
    }
    cout << n - k << endl;
    return 0;
}

