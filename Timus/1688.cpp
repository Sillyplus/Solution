/*******************************************************************************
	> File Name: 1688.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Mon Apr 27 11:51:31 2015
*******************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    double sum = 0, x;
    for (int i = 1; i <= m; i++) {
        cin >> x;
        sum += x;
        if (sum / 3.0 > n) {
            printf("Free after %d times.\n", i);
            break;
        }
    }
    if (sum / 3.0 <= n) {
        cout << "Team.GOV!" << endl; 
    }
    return 0;
}
