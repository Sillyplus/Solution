#include <iostream>

using namespace std;

int week(int y, int m, int d) {
    int ret;
    if (m < 3) {
        y--;
        m += 12;
    }
    int c = y/100;
    y %= 100;
    ret = (y + y/4 + c/4 - 2*c + (26*(m+1)/10) + d - 1) % 7;
    return ret;
}

int main() {
    int n, ans = 0;;
    cin >> n;
    for (int i = n+1; i <= 2010; i++)
        for (int j = 1; j <= 12; j++) {
            if (j == 2) continue;
            if (week(i, j, 30) == 5)
                ans++;
        }
    cout << ans << endl;
    return 0;
}
