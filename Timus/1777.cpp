/*******************************************************************************
	> File Name: 1777.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Wed Jan 14 15:03:22 2015
 ******************************************************************************/

#include <iostream>
#include <cmath>
#include <set>

using namespace std;

typedef long long LL;
const LL INF = 1e18 + 10;;

multiset<LL> s;
multiset<LL>::iterator itr;

int main() {
    LL mi, k;
    for (int i = 0; i < 3; i++) {
        cin >> k;
        s.insert(k);
    }
    int ans = 0;
    while (true) {
        mi = INF;
        ans++;
        LL pre;
        itr = s.begin();
        pre = *itr;
        for (itr++; itr != s.end(); itr++) {
            mi = min(mi, *itr - pre);
            pre = *itr;
        }
        if (mi == 0)
            break;
        else 
            s.insert(mi);
    }
    cout << ans << endl;
    return 0;
}
