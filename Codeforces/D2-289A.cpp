/*******************************************************************************
	> File Name: D2-289A.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Sat Jan 31 19:36:52 2015
 ******************************************************************************/

#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

const int MAXN = 1010;

int a[MAXN][MAXN];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        a[i][1] = a[1][i] = 1;
    for (int i =2; i <= n; i++)
        for (int j = 2; j <= n; j++)
            a[i][j] = a[i-1][j] + a[i][j-1];
    cout << a[n][n] << endl;
    return 0;
}
