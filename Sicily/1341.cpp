//
//  main.cpp
//  p1341
//
//  Created by Silly on 14-4-1.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

int a[110] = {0};

int main(int argc, const char * argv[])
{
    int n, k;
    set<int> st;
    set<int>::iterator its;
    while (cin >> n) {
        st.clear();
        for (int i = 0; i < n; i++) {
            cin >> k;
            st.insert(k);
        }
        cout << st.size() << endl;
        its = st.begin();
        cout << *its;
        for (its++ ; its != st.end(); its++) {
            cout << ' ' << *its;
        }
        cout << endl;
    }
    return 0;
}

