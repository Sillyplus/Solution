/*******************************************************************************
	> File Name: 1306.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Thu May 14 08:51:13 2015
*******************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

typedef long long LL;

int main() {
    int n, m, x;
    cin >> n;
    m = n / 2 + 1;
    priority_queue<int> q;
    for (int i = 0; i < m; i++) {
        cin >> x;
        q.push(x);
    }
    for (int i = m; i < n; i++) {
        cin >> x;
        if (x < q.top()) {
            q.pop();
            q.push(x);
        }
    }
    if (n % 2) {
        cout << q.top() << endl;
    } else {
        double ans = 0;
        ans = q.top();
        q.pop();
        ans += q.top();
        ans /= 2.0;
        printf("%.1f\n", ans);
    }
    return 0;
}
