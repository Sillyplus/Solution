#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int s[10];

bool check(int x) {
    bool ret = true;
    int l = 0;
    if (x < 100) return true;
    while (x) {
        s[l++] = x % 10;
        x /= 10;
    }
    for (int i = 1; i < l-1; i++) {
        if ((s[i-1] + s[i+1] != s[i]) &&
            (s[i-1] - s[i+1] != s[i]) &&
            (s[i+1] - s[i-1] != s[i]))
                return false;
    }
    return ret;
}

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        if (check(i))
            ans++;
    cout << ans << endl;
    return 0;
}
