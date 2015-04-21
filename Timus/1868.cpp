/*******************************************************************************
	> File Name: 1868.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Mon Apr 20 07:55:47 2015
*******************************************************************************/

#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> tl;
int ans[20] = {0};

int main() {
    string name, a, b, c;
    for (int i = 0; i < 12; i++) {
        cin >> name; 
        tl[name] = i / 4 + 1;
    }
    tl["gold"] = 1;
    tl["silver"] = 2;
    tl["bronze"] = 3;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k, tmp = 0;
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> a >> b >> c;
            if (tl[a] == tl[c]) tmp++;
        }
        ans[tmp]++;
    }
    int k;
    for (k = 12; k >= 0; k--)
        if (ans[k] != 0) break;
    cout << ans[k]*5 << endl;
    return 0;
}
