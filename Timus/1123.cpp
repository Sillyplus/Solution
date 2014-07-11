#include <iostream>
#include <string>

using namespace std;

const int MN = 2010;

int f[MN] = {0};

int main() {
    string s;
    cin >> s;
    int l = s.length();
    for (int i = 1; i <= l; i++) f[i] = s[i-1]-'0';
    for (int i = 1; i <= l/2; i++) {
        if (f[l-i+1] > f[i]) {
            int j = l-i;
            while (f[j] == 9) {
                f[j] = 0;
                j--;
            }
            f[j]++;
        }
        f[l-i+1] = f[i];
    }
    for (int i = 1; i <= l; i++) cout << f[i]; cout << endl;
    return 0;
}
