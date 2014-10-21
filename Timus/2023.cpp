#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

int n;
set<char> s1, s2, s3;

int main() {
    cin >> n;
    s1.insert('A'), s1.insert('P'), s1.insert('O'), s1.insert('R');
    s2.insert('B'), s2.insert('M'), s2.insert('S');
    s3.insert('D'), s3.insert('G'), s3.insert('J'), s3.insert('K'), s3.insert('T');
    s3.insert('W');
    string s;
    int pos = 1, ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> s;
        int now;
        if (s1.find(s[0]) != s1.end()) now = 1;
        if (s2.find(s[0]) != s2.end()) now = 2;
        if (s3.find(s[0]) != s3.end()) now = 3;
        ans += abs(pos - now);
        pos = now;
    }
    cout << ans << endl;
    return 0;
}
