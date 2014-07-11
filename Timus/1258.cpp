#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>

using namespace std;

int main() {
    double w, d, x1, y1, x2, y2, x, y;
    string s;
    cin >> w >> d;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        switch (s[i]) {
            case 'F':
                y1 = -y1;
                break;
            case 'B':
                y1 = 2 * d - y1;
                break;
            case 'L':
                x1 = -x1;
                break;
            case 'R':
                x1 = 2 * w - x1;
                break;
        }
        cout << x1 << ' ' << y1 << endl;
    }
    double ans;
    ans = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    printf("%.4f\n", ans);
    return 0;
}
