/*******************************************************************************
	> File Name: 1638.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Tue Jan  6 15:51:36 2015
 ******************************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << abs((d-c)*(a+b+b) - a) << endl;
    return 0;
}
