//
//  main.cpp
//  set1
//
//  Created by Silly on 14-2-3.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <set>

using namespace std;

int main(int argc, const char * argv[])
{
    set<int> s;
    s.insert(8);
    s.insert(1);
    s.insert(12);
    s.insert(5);
    s.insert(8);
    set<int>::iterator it;
    for (it = s.begin(); it != s.end(); it++) {
        cout << *it << ' ';
    }
    cout << endl;
    set<int>::reverse_iterator rit;
    for (rit = s.rbegin(); rit != s.rend(); rit++) {
        cout << *rit << " ";
    }
    cout << endl;
    s.erase(5);
    for (rit = s.rbegin(); rit != s.rend(); rit++) {
        cout << *rit << ' ';
    }
    cout << endl;
    s.clear();
    cout << s.size() << endl;
    it = s.find(1);
    if (it != s.end()) {
        cout << *it << endl;
    } else {
        cout << "Not find it!" << endl;
    }
    it = s.find(20);
    if (it != s.end()) {
        cout << *it << endl;
    } else {
        cout << "Not find it!" << endl;
    }
    return 0;
}

