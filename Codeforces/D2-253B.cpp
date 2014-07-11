#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string s;

bool ck(int l, int r) {
    if ((r-l+1)%2 != 0) return false;
    int mid = (r-l+1)/2;
    for (int i = 0; i < mid; i++) {
        if (s[l+i+mid] == '*') continue;
        if (s[l+i] != s[l+i+mid]) return false;
    }
    return true;
}

int main() {
    int k;
    cin >> s;
    cin >> k;
    int l = s.length();
    for (int i = 0; i < k; i++)
        s += '*';
    int ans = 0;
    int ml = l/2;
    for (int i = 0; i < l; i++) {
        for (int j = l+k-1; j > i; j--) {
            if (ck(i, j)) {
                ans = max(ans, (j-i+1));
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
