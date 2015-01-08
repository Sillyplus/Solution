/*******************************************************************************
	> File Name: 1192.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Thu Jan  8 22:53:57 2015
 ******************************************************************************/

#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

const double g = 10.0;
const double pi = 3.1415926535;
const double INF = 0.00001;

int main() {
    double v, a, k, s = 0;
    cin >> v >> a >> k;
    double A = a * pi / 180;
    while (v > INF) {
        s += (2*v*v*sin(A)*cos(A) / g);
        v = sqrt(v*v/k);
    }
    printf("%.2f\n", s);    
    return 0;
}
