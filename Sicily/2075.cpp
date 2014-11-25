/*******************************************************************************
	> File Name: 2075.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Tue Nov 25 15:22:47 2014
 ******************************************************************************/

#include <iostream>

using namespace std;

double radius, length;

int main() {
    cin >> radius >> length;
    double PI = 3.14159;
    double ans;
    ans = radius * radius * PI * length;
    cout << ans << endl;
    return 0;
}
