#include <iostream>
#include <string>

using namespace std;

int n;
string s;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        int ans = 0, k = 0;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == 'O') {
                k++;
                ans += k;
            } else {
                k = 0;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
