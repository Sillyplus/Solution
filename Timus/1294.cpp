#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a*b == c*d) {
        cout << "Impossible." << endl;
        return 0;
    }
    double ans;
    ans = (c*d*(a*a + b*b) - a*b*(c*c + d*d))/(c*d - a*b);
    ans = sqrt(ans) * 1000;
    printf("Distance is %.0f km.\n", ans);
    return 0;
}
