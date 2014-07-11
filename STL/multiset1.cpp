//
//  main.cpp
//  mulitset1
//
//  Created by Silly on 14-3-2.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <set>

using namespace std;

int main(int argc, const char * argv[])
{
    multiset<string> ms;
    ms.insert("abc");
    ms.insert("123");
    ms.insert("111");
    ms.insert("aaa");
    ms.insert("aaa");
    ms.insert("123");
    multiset<string>::iterator it;
    for (it = ms.begin(); it != ms.end(); it++) {
        cout << *it << endl;
    }
    
    it = ms.find("123");
    if (it != ms.end()) {
        cout << *it << endl;
    } else {
        cout << "Not find it" << endl;
    }
    
    unsigned long n = ms.erase("123");
    cout << "Total deleted : " << n << endl;
    for (it = ms.begin(); it != ms.end(); it++) {
        cout << *it << endl;
    }
    
    it = ms.find("123");
    if (it != ms.end()) {
        cout << *it << endl;
    } else {
        cout << "Not find it" << endl;
    }
    return 0;
}

