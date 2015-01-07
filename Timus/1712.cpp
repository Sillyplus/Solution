/*******************************************************************************
	> File Name: 1712.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Wed Jan  7 21:52:22 2015
 ******************************************************************************/

#include <iostream>

using namespace std;

char c[10][10];
char w[10][10];

void rotate() {
    char t[10][10];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            t[i][j] = c[4-j-1][i];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            c[i][j] = t[i][j];
}

int main() {
    for (int i = 0; i < 4; i++)
        cin >> c[i];
    for (int i = 0; i < 4; i++)
        cin >> w[i];
    string ans;
    for (int t = 0; t < 4; t++) {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                if (c[i][j] == 'X')
                    ans += w[i][j];
        rotate();
    }
    cout << ans << endl;
    return 0;
}
