#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    string s1, s2;
    int ans = 0;
    cin >> s1 >> s2;
    for (int i = 0; i < s1.length(); i++) {
        bool flag = true;
        for (int j = 0, k = (s2.length()-i-1); j < i; j++, k++) {
            if (s1[j] != s2[k]) {
                flag = false;
                break;
            }
        }
        if (flag)
            ans = max(ans, i+1);
    }
    for (int i = 0; i < s2.length(); i++) {
        bool flag = true;
        for (int j = 0, k = (s1.length()-i-1); j < i; j++, k++) {
            if (s2[j] != s1[k]) {
                flag = false;
                break;
            }
        }
        if (flag)
            ans = max(ans, i+1);
    }
    cout << ans << endl;
    return 0;
}
