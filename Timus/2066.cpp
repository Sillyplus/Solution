/*******************************************************************************
	> File Name: 2066.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Sat Oct 31 08:01:25 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    int a, b, c;
    cin >> a >> b >> c;
    if (b > 1) {
        cout << a - b * c << endl;
    } else {
        cout << a - b - c << endl;
    }
    return 0;
}
