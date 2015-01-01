/*******************************************************************************
	> File Name: 1567.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Sun Dec 28 23:34:03 2014
 ******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

string s;

int main() {
    int ans = 0;
    getline(cin, s);
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == ' ') ans++;
        if (s[i] == '.') ans++;
        if (s[i] == ',') ans += 2;
        if (s[i] == '!') ans += 3;
        if (s[i] >= 'a' && s[i] <= 'z')
            ans += ((s[i] - 'a') % 3) + 1;
    }
    cout << ans << endl;
    return 0;
}
