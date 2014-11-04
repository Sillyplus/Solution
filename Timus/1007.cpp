#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

const int MN = 1010;

int sum[MN];
int n;

int main() {
    cin >> n;
    string s;
    while (cin >> s) {
        int len = s.size();
        int total = 0;
        memset(sum, 0, sizeof(sum));
        for (int i = len-1; i >= 0; i--) {
            if (s[i] == '1') {
                sum[i] = sum[i+1] + 1;
                total += i+1;
            } else {
                sum[i] = sum[i+1];
            }
        }
        if (len == n) {
            if (total % (n+1)) {
                s[(total % (n+1)) - 1] = '0';
            }
        } else if (len < n) {
            for (int i = len; i >= 0; i--) {
                if (((total + sum[i]) % (n+1)) == 0) {
                    s.insert(i, "0");
                    break;
                }
                if (((total + sum[i] + (i+1)) % (n+1)) == 0) {
                    s.insert(i, "1");
                    break;
                }
            }
        } else if (len > n) {
            for (int i = len-1; i >= 0; i--) {
                if ((s[i] == '1') && ((total - sum[i] - i) % (n+1)) == 0) {
                    s.erase(i, 1);
                    break;
                }
                if ((s[i] == '0') && ((total - sum[i]) % (n+1)) == 0) {
                    s.erase(i, 1);
                    break;
                }
            }
        }
        cout << s << endl;
    }
    return 0;
}
