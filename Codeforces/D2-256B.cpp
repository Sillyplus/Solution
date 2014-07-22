#include <iostream>
#include <string>

using namespace std;

const int MN = 30;

int cs[MN], ct[MN];
string s, t;
bool at, ar;

int main() {
    cin >> s >> t;
    for (int i = 0; i < s.length(); i++)
        cs[s[i]-'a']++;
    for (int i = 0; i < t.length(); i++)
        ct[t[i]-'a']++;
    at = ar = false;

    for (int i = 0; i < 26; i++)
        if (cs[i] != ct[i]) {
            if (cs[i] < ct[i]) {
                cout << "need tree" << endl;
                return 0;
            }
            at = true;
        }

    int ts = 0, tt = 0;
    for (int i = 0; i < t.length(); i++) {
        while ((s[ts] != t[i]) && (ts < s.length())) ts++;
        if (ts == s.length()) break;
        if (s[ts] == t[i]) {
            tt++;
            ts++;
        }
    }
    if (tt != t.length()) ar = true;
    if (at && ar) {
        cout << "both" << endl;
    } else if (at) {
        cout << "automaton" << endl;
    } else {
        cout << "array" << endl;
    }
    return 0;
}
