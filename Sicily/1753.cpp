//
//  main.cpp
//  p1753
//
//  Created by Silly on 14-4-3.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

string ss, s;

int main(int argc, const char * argv[])
{
    cin >> s;
    while (s != "XXX") {
        string c;
        int k = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] <= '9') {
                if (k == 0) {
                    c = s[i-1];
                } else k = k * 10;
                k += s[i] - '0';
            } else {
                if (k) {
                    for (int j = 1; j < k; j++) {
                        ss += c;
                    }
                    k = 0;
                    c = "";
                }
                ss += s[i];
            }
        }
        if (k) {
            for (int j = 1; j < k; j++) {
                ss += c;
            }
        }
        cout << ss << endl;
        ss = "";
        cin >> s;
    }
    return 0;
}

