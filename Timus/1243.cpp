/*******************************************************************************
	> File Name: 1243.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Fri Jan  2 14:31:07 2015
 ******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int tmp = 0;
    for (int i = 0; i < s.size(); i++) {
        tmp = tmp * 10 + (s[i] - '0');
        tmp %= 7;
    }
    cout << tmp << endl;
    return 0;
}
