/*******************************************************************************
    > File Name: 2035.cpp
    > Author: sillyplus
    > Mail: oi_boy@sina.cn
    > Created Time: Tue Dec  2 18:48:14 2014
 ******************************************************************************/

#include <iostream>

using namespace std;

int main() {
    int x, y, c;
    cin >> x >> y >> c;
    if (x <= c) {
        if (c-x <= y) {
            cout << x << " " << c-x << endl;
            return 0;
        }
    }
    if (y <= c) {
        if (c-y <= x) {
            cout << c-y << " " << y << endl;
            return 0;
        }
    }
    if (x >= c && y >= c)
        cout << c << " " << 0 << endl;
    else
        cout << "Impossible" << endl;
    return 0;
}
