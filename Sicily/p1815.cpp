#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    double x1, x2, y1, y2;
    while (n--) {
        cin >> x1 >> y1 >> x2 >> y2;
        double ans;
        ans = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
        ans = sqrt(ans);
        printf("%.2f\n", ans);
    }
    return 0;
}
