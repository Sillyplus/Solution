//
//  main.cpp
//  D2－217A
//
//  Created by Silly on 13-12-7.
//  Copyright (c) 2013年 Silly. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[])
{
    int r1 = 0, c1 = 0, r2 = 0, c2 = 0;
    cin >> r1 >> c1 >> r2 >> c2;
    cout << ((r1 == r2) or (c1 == c2) ? 1 : 2) << " ";
    cout << ( (((r1 + c1) % 2) != ((r2 + c2) % 2) )? 0 : (abs(r1 - r2) == abs(c1 - c2) ? 1 : 2) ) << " ";
    cout << (min(abs(r1 - r2), abs(c1 - c2)) + abs(abs(r1 - r2) - abs(c1 - c2))) << endl;
     return 0;
}

