/*******************************************************************************
	> File Name: 1060.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Sat Jan 17 17:39:13 2015
 ******************************************************************************/

#include <iostream>
#include <cstring>

using namespace std;

const int INF = 1e9;

char c[10][10];
int a[10][10];
int dx[] = {-1, 0, 0, 0, 1};
int dy[] = {0, -1, 0, 1, 0};

int sol(int x) {
    int ret = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (c[i][j] == 'b')
                a[i+1][j+1] = 1;
            else 
                a[i+1][j+1] = 0;
        }
    }
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            if (x % 2) {
                ret++;
                for (int k = 0; k < 5; k++)
                    a[i+dx[k]][j+dy[k]] ^= 1;
            }
            x /= 2;
        }
    }
    int tmp = 0;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            tmp += a[i][j];
        }
    }
    if (tmp != 0 && tmp != 16)
        ret = INF;
    return ret;
}

int main() {
    for (int i = 0; i < 4; i++)
        cin >> c[i];
    int ans = INF;
    for (int i = 0; i < (1 << 16); i++) {
        int tmp = sol(i);
        ans = min(ans, tmp);
    }
    if (ans == INF) 
        cout << "Impossible" << endl;
    else
    cout << ans << endl;
    return 0;
}
