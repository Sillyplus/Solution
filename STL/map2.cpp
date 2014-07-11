//
//  main.cpp
//  map2
//
//  Created by Silly on 14-3-2.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>

using namespace std;

struct myComp{
    bool operator() (const int &a, const int &b){
        if (a != b)
            return a > b;
        else
            return a > b;
    }
};


int main(int argc, const char * argv[])
{
    map<int, char, myComp> m;
    m[25] = 'm';
    m[28] = 'k';
    m[10] = 'x';
    m[30] = 'a';
    
//    m.erase(28);
    
    map<int, char, myComp>::iterator it;
    for (it = m.begin(); it != m.end(); it++) {
        cout << (*it).first << " : " << (*it).second << endl;
    }
    return 0;
}

