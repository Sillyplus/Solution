//
//  main.cpp
//  p1007
//
//  Created by Silly on 14-3-31.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

string s, ss;

int main(int argc, const char * argv[])
{
    int k;
    cin >> k;
    while (k) {
        cin >> s;
        ss = "";
        int flag = 1;
        int l = s.length();
        while (!s.empty()) {
            if (flag) {
                //cout << "1\n";
                for (int i = 0; i < k; i++) {
                    ss += s[i];
                }
            } else {
                //cout << "2\n";
                for (int i = k-1; i >= 0; i--) {
                    ss += s[i];
                }
            }
            flag ^= 1;
            s.erase(s.begin(), s.begin() + k);
        }
        //cout << ss << endl;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < l / k; j++) {
                cout << ss[i + j*k];
            }
        }
        cout << endl;
        cin >> k;
    }
    return 0;
}

