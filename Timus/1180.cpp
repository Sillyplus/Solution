/*******************************************************************************
	> File Name: 1180.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Thu Nov 13 17:37:15 2014
 ******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

int main() {
    int sum = 0;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        sum += s[i] - '0';
    }
    if (sum % 3 == 0)
        cout << 2 << endl;
    else {
        cout << 1 << endl;
        cout << sum % 3 << endl;
    }
    return 0;
}
