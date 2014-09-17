#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main() {
    int t;
    double x1, x2, x3, y1, y2, y3, ans;
    cin >> t;
    while (t--) {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        ans = 0;
        ans = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2)) +
                sqrt(pow(x1-x3, 2) + pow(y1-y3, 2)) +
                  sqrt(pow(x3-x2, 2) + pow(y3-y2, 2));
        printf("%.5f\n", ans);
    }
    return 0;
}
