//
//  main.cpp
//  p1134
//
//  Created by Silly on 14-4-1.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct xx{
    int a, b;
};

bool comp(const xx &x, const xx &y){
    if (x.b != y.b) {
        return x.b < y.b;
    } else return x.a < y.a;
}

vector<xx> v;
int n, s;

int main(int argc, const char * argv[])
{
    cin >> n >> s;
    xx k;
    while (n) {
        for (int i = 0; i < n; i++) {
            cin >> k.a >> k.b;
            v.push_back(k);
        }
        sort(v.begin(), v.end(), comp);
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (s >= v[i].b) {
                s += v[i].a;
            } else flag = false;
        }
        if (flag) {
            cout << "YES\n";
        } else cout << "NO\n";
        v.clear();
        cin >> n >> s;
    }
    return 0;
}

