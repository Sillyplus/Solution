/*******************************************************************************
	> File Name: 1545.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Sun Jan  4 15:21:16 2015
 ******************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 1001;

string v[MAXN];

int main() {
    int n;
    char c;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v, v+n);
    cin >> c;
    for (int i = 0; i < n; i++) {
        if (v[i][0] == c)
            cout << v[i] << endl;
    }
    return 0;
}
