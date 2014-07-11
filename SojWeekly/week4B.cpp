//
//  main.cpp
//  week4B
//
//  Created by Silly on 14-3-22.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

const int MN = 55;

char a[MN][MN];
int n, m;
int xx[8] = {-1,-1,-1, 0,0, 1,1,1};
int yy[8] = {-1, 0, 1,-1,1,-1,0,1};

int sch() {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'o') {
                for (int k = 0; k < 8; k++) {
                    if ((i+xx[k] >= 0) && (i+xx[k] < n) && (j+yy[k] >= 0) && (j+yy[k] < m)) {
                      //  cout << i+xx[k] << ' ' << j+yy[k] << endl;
                        if (a[i+xx[k]][j+yy[k]] == 'o') {
                            ans++;
                        }
                    }
                }
            }
        }
    }
    //cout << ans << endl;
    return ans;
}

int main(int argc, const char * argv[])
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    }
    int mx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int tmx = 0;
            if (a[i][j] != 'o') {
                a[i][j] = 'o';
                tmx = sch();
                a[i][j] = '.';
            };
            if (tmx > mx) {
                mx = tmx;
            }
        }
    }
    int tmx;
    tmx = sch();
    mx = max(mx, tmx);
    cout << mx/2 << endl;
    return 0;
}

