#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>

using namespace std;

const int MN = 10010;

string s[MN];
vector<string> v;
vector<string>::iterator its;

bool check(string x) {
    int l = x.length();
    for (int i = 0; i < l/2; i++) {
        if (x[i] != x[l-i-1]) return false;
    }
    return true;
}

int main() {
    int n, t;
    cin >> t;
    while (t--) {
        cin >> n;
        string ss;
        for (int i = 0; i < n; i++) cin >> s[i];
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++) {
                if (s[i] != s[j]) {
                    ss = s[i] + s[j];
                    v.push_back(ss);
                    ss = s[j] + s[i];
                    v.push_back(ss);
                }
            }
        bool flag = false;
        for (its = v.begin(); its != v.end(); its++){
            if (check(*its)) {
                cout << "Yes\n";
                flag = true;
                break;
            }
        }
        if (!flag) cout << "No\n";
        v.clear();
    }
    return 0;
}
