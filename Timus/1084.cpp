/*******************************************************************************
	> File Name: 1084.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Fri Jan 16 22:45:36 2015
 ******************************************************************************/

#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

const double PI = 3.141592653;
const double root2 = 1.4142135623;

int main() {
    double l, r, area;
    cin >> l >> r;
    if (r < l/2) {
        area = PI * r * r;
    } else if (r > (l/2)*root2) {
        area = l * l;
    } else {
        double tmp = PI * r * r;
        area = 2 * l * sqrt(r*r - (l/2)*(l/2));
        area += (2 * PI - 8 * acos(l/2/r)) / (2 * PI) * tmp;
    }
    printf("%.3f\n", area);
    return 0;
}
