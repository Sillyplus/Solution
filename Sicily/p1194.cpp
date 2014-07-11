//
//  main.cpp
//  p1194
//
//  Created by Silly on 14-3-31.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[])
{
    int n, m;
    cin >> n;
    string s;
    set<string> se;
    set<string>::iterator it;
    while (n) {
        cin >> m;
        for (int i = 0; i < n; i++) {
            cin >> s;
            transform(s.begin(), s.end(), s.begin(), ::tolower);
            se.insert(s);
        }
        for (int i = 0; i < m; i++) {
            cin >> s;
            transform(s.begin(), s.end(), s.begin(), ::tolower);
            it = se.find(s);
            if (it != se.end()) {
                se.erase(s);
            }
        }
        cout << se.size() << endl;
        se.clear();
        cin >> n;
    }
    return 0;
}

