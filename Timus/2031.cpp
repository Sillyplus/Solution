/*******************************************************************************
	> File Name: 2031.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Tue Jan 13 10:41:44 2015
 ******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

string a[] = {"11", "11 01", "06 68 88", "16 06 68 88"};

int main() {
    int n;
    cin >> n;
    if (n > 4) {
        cout << "Glupenky Pierre" << endl;
    } else {
        cout << a[n-1] << endl;
    }
    return 0;
}
