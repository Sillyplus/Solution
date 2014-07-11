#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    if (s.length() < 5) {
        cout << "Too weak" << endl;
        return 0;
    }
    int l = 0, ss = 0, t = 0, d = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9') d++;
        if (s[i] >= 'a' && s[i] <= 'z') ss++;
        if (s[i] >= 'A' && s[i] <= 'Z') l++;
    }
    if (d && ss && l) {
        cout << "Correct" << endl;
    } else {
        cout << "Too weak" << endl;
    }
    return 0;
}
