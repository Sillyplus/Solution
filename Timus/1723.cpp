#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

string s;

int a[30] = {0};

int main() {
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        int k = s[i] - 'a';
        a[k]++;
    }
    int ans = 0, pos = 0;
    for (int i = 0; i < 26; i++) {
        if (a[i] > ans) {
            ans = a[i];
            pos = i;
        }
    }
    cout << char(pos+'a') << endl;
    return 0;
}
n
