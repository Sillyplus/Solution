#include <iostream>

using namespace std;

int n, k, a1, a2;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        if (k == 100)
            a1++;
        else
            a2++;
    }
    string ans;
    if (a2 % 2) {
        if ((a1 >= 2) && (a1 % 2 == 0)) {
            ans = "YES";
        } else {
            ans = "NO";
        }
    } else {
        if (a1 % 2 == 0) {
            ans = "YES";
        } else {
            ans = "NO";
        }
    }
    cout << ans << endl;
    return 0;
}
