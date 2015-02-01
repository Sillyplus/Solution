/*******************************************************************************
	> File Name: 2020.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Sat Jan 31 08:30:17 2015
 ******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

int main() {
    string a, b;
    cin >> a;
    cin >> b;
    int ans = 0;
    for (int i = 0, j = 0; ; ) {
        if (i >= a.size() || j >= b.size()) {
            ans += a.size() - i;
            ans += b.size() - j;
            break;
        }
        if ((a[i] == 'L' && b[j] == 'L') || (a[i] != 'L' && b[j] != 'L')) {
            ans++;
            i++, j++;
            continue;
        }
        if (a[i] == 'L') {
            ans++;
            j++;
        } else {
            ans++;
            i++;
        }
    }
    cout << ans << endl;
    return 0;
}
