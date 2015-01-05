/*******************************************************************************
	> File Name: 1404.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Mon Jan  5 12:46:48 2015
 ******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

const int MAXN = 110;

int a[MAXN];

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        a[i] = s[i] - 'a';
    }
    a[0] = (a[0] - 5 + 26) % 26;
    a[0] += 5;
    for (int i = 1; i < s.size(); i++) {
        while (a[i] < a[i-1]) a[i] += 26;
    }
    for (int i = s.size()-1; i > 0; i--) {
        a[i] -= a[i-1];
    }
    a[0] -= 5;
    for (int i = 0; i < s.size(); i++) {
        cout << char('a'+a[i]);
    }
    return 0;
}
