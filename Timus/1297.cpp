#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const int MN = 1010;

int f[MN][MN] ={0};

int main() {
    string s;
    cin >> s;
    int ans = 1;
    f[0][1] = 1;
    for (int i = 1; i < s.length(); i++) {
        f[i][1] = 1;
        if (s[i] == s[i-1]) {
            f[i][2] = 2;
            ans = max(ans, 2);
        }
        for (int j = 3; j <= i+1; j++) {
            if (s[i] == s[i-j+1] && f[i-1][j-2] != 0) {
                f[i][j] = f[i-1][j-2] + 2;
                ans = max(ans, f[i][j]);
            }
        }
    }
    for (int i = 0; i < s.length(); i++)
        for (int j = 1; j <= i+1; j++)
            if (f[i][j] == ans) {
                for (int k = i-j+1; k <= i; k++)
                    cout << s[k];
                cout << endl;
                return 0;
            }
    return 0;
}
