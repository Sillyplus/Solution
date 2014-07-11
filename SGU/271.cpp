//
//  main.cpp
//  sgu271
//
//  Created by Silly on 14-3-26.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int n , m, k;
char ch;
string st;

int main(int argc, const char * argv[])
{
    deque<string> c;
    vector<string> v;
    vector<string>::iterator vit;
    deque<string>::iterator dit;
    deque<string>::reverse_iterator rit;
    int flag = 1;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> st;
        c.push_back(st);
    }
    while (c.size() > k) {
        rit = c.rbegin();
        v.push_back(*rit);
        c.pop_back();
    }
    for (int i = 0; i < m; i++) {
        cin >> st;
        if (st[0] == 'A') {
            string tmp;
            tmp = "";
            for (int i = 4; st[i] != ')'; i++) {
                tmp += st[i];
            }
            if (!flag) {
                c.push_back(tmp);
                if (c.size() > k) {
                    dit = c.begin();
                    v.push_back(*dit);
                    c.pop_front();
                }
            } else {
                c.push_front(tmp);
                if (c.size() > k) {
                    rit = c.rbegin();
                    v.push_back(*rit);
                    c.pop_back();
                }
            }
        } else {
            flag ^= 1;
        }
    }
    if (!flag) {
        for (rit = c.rbegin(); rit != c.rend(); rit++) {
            cout << *rit << endl;
        }
    } else {
        for (dit = c.begin(); dit != c.end(); dit++) {
            cout << *dit << endl;
        }
    }
    for (vit = v.end()-1; vit >= v.begin(); vit--) {
        cout << *vit << endl;
    }
    return 0;
}

