#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1' || s[i] == '5') ans++;
        if (s[i] == '2' || s[i] == '4' || s[i] == '6' || s[i] == '9') ans += 2;
        if (s[i] == '3' || s[i] == '7') ans += 3;
        if (s[i] == '8') ans += 4;
    }
    cout << ans << endl;
    return 0;
}
