#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

const int MN = 100010;

int a[5];
string s;

int main() {
    for (int i = 1; i <= 4; i++) {
        cin >> a[i];
    }
    cin >> s;
    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
        ans += a[s[i]-'0'];
    }
    cout << ans << endl;
    return 0;
}
