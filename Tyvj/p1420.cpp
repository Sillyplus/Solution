//
//  main.cpp
//  p1420
//
//  Created by Silly on 14-1-29.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[])
{
    string n, m;
    cin >> n;
    cin >> m;
    if ((m[m.length() - 1] - '0') % 2 == 1) {
        cout << "Yes\n";
    } else cout << "No\n";
    return 0;
}

