#include <iostream>
#include <string>

using namespace std;

const int MN = 1010;

string n, m;

int main() {
    int t, flag;
    cin >> t;
    while (t--) {
        flag = 0;
        cin >> n >> m;
        if (n != m) {
            flag = 1;
        } else {
            int k = n[0] - '0';
            for (int i = 1; i < n.length(); i++) {
                k = k*10 + (n[i]- '0');
                k %= 11;
            }
            if (k != 0) flag = 1;
        }
        if (flag) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}
