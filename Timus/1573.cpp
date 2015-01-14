/*******************************************************************************
	> File Name: 1573.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Wed Jan 14 14:48:53 2015
 ******************************************************************************/

#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> mp;
int a[10];

int main() {
    mp["Blue"] = 0;
    mp["Red"] = 1;
    mp["Yellow"] = 2;
    for (int i = 0; i < 3; i++)
        cin >> a[i];
    int k, ans = 1;
    string s;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> s;
        ans *= a[mp[s]];
    }
    if (k == 0) 
        cout << 0 << endl;
    else 
        cout << ans << endl;
    return 0;
}
