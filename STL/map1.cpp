//
//  main.cpp
//  map1
//
//  Created by Silly on 14-3-2.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(int argc, const char * argv[])
{
    map<string, float> m;
    m["Jack"] = 98.5;
    m["Bomi"] = 96.0;
    m["Kate"] = 97.5;
    map<string, float>::iterator it;
    for (it = m.begin(); it != m.end(); it++) {
        cout << (*it).first << " : " << (*it).second << endl;
    }
    return 0;
}

