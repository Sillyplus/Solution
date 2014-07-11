//
//  main.cpp
//  week3D
//
//  Created by Silly on 14-3-15.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <cstdio>
#include <algorithm>

using namespace std;

int a[250010] ={0};
int tl;

int main(int argc, const char * argv[])
{
    int n, g;
    cin >> n >> g;
    set<int> s;
    set<int>::iterator it;
    int k, x;
    cin >> k;
    for (int i = 0; i < k; i++) {
        scanf("%d", &x);
        s.insert(x);
    }
    //cout << s.size() << endl;
    tl = 0;
    for (int i = 1; i < g; i++) {
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &x);
            it = s.find(x);
            if (it == s.end()) {
                a[tl] = x;
                tl++;
            }
        }
        if (tl == 1 && k > 1) {
            s.insert(a[0]);
        }
        tl = 0;
    }
    cout << s.size() << endl;
    return 0;
}

