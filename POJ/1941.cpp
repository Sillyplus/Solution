/*******************************************************************************
	> File Name: 1.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Wed Oct 28 00:32:45 2015
*******************************************************************************/

#include <iostream>
#include <stdio.h>

using namespace std;

const int MAXN = 2100;

int n;

char mp[MAXN][MAXN];

void pt(int x, int y, int r) {
    if (r == 2) {
        mp[x][y+1] = '/';
        mp[x][y+2] = '\\';
        mp[x+1][y] = '/';
        mp[x+1][y+1] = '_';
        mp[x+1][y+2] = '_';
        mp[x+1][y+3] = '\\';
    } else {
        pt(x+(r >> 1), y, r >> 1);
        pt(x+(r >> 1), y+r, r >> 1);
        pt(x, y + (r >> 1), r >> 1);
    }
}

int main(int argc, char* argv[]) {
    while (scanf("%d", &n) == 1 && n) {
        int r;
        r = 1 << n;
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < r*2; ++j)
                mp[i][j] = ' ';
        pt(0, 0, r);
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j <= r + i; ++j)
                cout << mp[i][j];
            cout << endl;
        }
        cout << endl;
    }    
    return 0;
}
