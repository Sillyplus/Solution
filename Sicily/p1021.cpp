//
//  main.cpp
//  sp1021
//
//  Created by Silly on 14-3-3.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

int f[200100] = {0};

int main(int argc, const char * argv[])
{
    int n;
    while (cin >> n && n) {
        stack<int> s;
        int a, b;
        for (int i = 1; i <= n; i++) {
            cin >> a >> b;
            f[a] = f[b] = i;
        }
        for (int i = 1; i <= 2*n; i++) {
            if (!s.empty() && s.top() == f[i]) s.pop();
                else s.push(f[i]);
        }
        if (s.empty()) {
            cout << "Yes" << endl;
        } else cout << "No" << endl;
    }
    return 0;
}

