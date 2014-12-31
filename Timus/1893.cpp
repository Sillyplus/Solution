/*******************************************************************************
	> File Name: 1893.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Wed Dec 31 17:24:30 2014
 ******************************************************************************/

#include <iostream>

using namespace std;

int main() {
    string s, ans;
    int num, c;
    cin >> s;
    if (s.size() == 2) {
        num = s[0]-'0';
        c = s[1]-'A'+1;
    } else {
        num = (s[0]-'0')*10 + s[1]-'0';
        c= s[2]-'A'+1;
    }
    if (c == 1 || (num < 3 && c == 4) || (num > 2 && num < 21 && c == 6) || (num > 20 && c == 11)) {
        ans = "window";
    } else if ((num < 3 && (c == 2 || c == 3)) || (num > 2 && num < 21 && (c > 1 && c < 6)) 
            || (num > 20 && (c == 3 || c == 4 || c == 7 || c == 8))) {
        ans = "aisle";
    } else {
        ans = "neither";
    }
    cout << ans << endl;
    return 0;
}
