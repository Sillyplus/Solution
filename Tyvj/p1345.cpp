#include <iostream>
#include <string>
#include <set>

using namespace std;

int n, m;
string a[110];
bool b[110] = {0};

string cvt(string s) {
    string ret = "";
    for (int i = 0; i < s.length(); i++)
        if ((s[i] >= 'A') && (s[i] <= 'Z'))
            ret += char(s[i]+32);
        else
            ret += s[i];
    return ret;
}

int main() {
    cin >> n >> m;
    string s, tmp;
    for (int i = 0; i < n; i++) {
        cin >> s;
        s = cvt(s);
        a[i] = s;
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        cin >> s;
        s = cvt(s);
        for (int j = 0; j < n; j++) {
            if (b[j]) continue;
            if ((s.find(a[j]) != -1) || (a[j].find(s) != -1)) {
                ans++;
                b[j] = true;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
