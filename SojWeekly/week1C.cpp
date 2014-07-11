//
//  main.cpp
//  week1C
//
//  Created by Silly on 14-3-2.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

const int MN = 3000010;

struct Mirko{
    int mass;
    int value;
    bool operator< (const Mirko &a) const{
        if (a.value != value)
            return a.value < value;
        else
            return a.mass > mass;
    }
};

int main(int argc, const char * argv[])
{
    int n, k;
    cin >> n >> k;
    multiset<Mirko> ms;
    Mirko x;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x.mass, &x.value);
        ms.insert(x);
    }
    multiset<int> mk;
    int t;
    for (int i = 0; i < k; i++) {
        scanf("%d", &t);
        mk.insert(t);
    }
    multiset<Mirko>::iterator it;
    multiset<int>::iterator ik;
    

    /*
    for (it = ms.begin(); it != ms.end(); it++) {
        cout << (*it).mass << " " << (*it).value << endl;
    }
    */
    
    return 0;
}

