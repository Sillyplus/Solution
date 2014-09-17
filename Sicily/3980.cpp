#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int t;
    string s;
    cin >> t;
    while (t--) {
        cin >> s;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            ans += ((s[s.size()-i-1] - '0') * pow(2, i));
        }
        cout << ans << endl;
    }
}
