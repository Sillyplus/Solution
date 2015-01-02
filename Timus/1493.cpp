/*******************************************************************************
	> File Name: 1493.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Fri Jan  2 14:41:35 2015
 ******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int now = 0;
    for (int i =0; i < s.size(); i++)
        now = now * 10 + (s[i]-'0');
    int pre, next;
    pre = now - 1;
    next = now + 1;
    int l1, l2, r1, r2;
    l1 = l2 = r1 = r2 = 0;
    for (int i = 0; i < 3; i++) {
        l1 += pre % 10;
        l2 += next % 10;
        pre /= 10;
        next /= 10;
    }
    for (int i = 0; i < 3; i++) {
        r1 += pre % 10;
        r2 += next % 10;
        pre /= 10;
        next /= 10;
    }
    if (l1 == r1 || l2 == r2)
        cout << "Yes" << endl;
    else 
        cout << "No" << endl;
    return 0;
}
