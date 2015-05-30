/*******************************************************************************
	> File Name: 135.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Fri May 29 10:56:28 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 65536 + 10;
long long f[MAXN];

int main(int argc, char* argv[]) {
    int n;
    cin >> n;
    f[0] = 1;
    for (int i = 1; i <= n; i++) 
        f[i] = f[i-1] + (long long)(i);
    cout << f[n] << endl;
    return 0;
}
