#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int n, ans;
string v[50];

void cal(string s) {
    int l = s.length();
    int sum = 0, rn = 0;
    char op = ' ';
    for (int i = 0; i < l; i++) {
        if (s[i] == ' ') continue;
        if (s[i] == '+' || s[i] == '-') {
            if (op == ' ') {
                op = s[i];
                sum = rn;
                rn = 0;
                continue;
            } else if (op == '+') {
                sum += rn;
            } else if (op == '-') {
                sum -= rn;
            }
            op = s[i];
            rn = 0;
        } else {
            rn = rn*10 + (s[i]-'0');
        }
    }
    if (rn != 0) {
        if (op == ' ') {
            sum = rn;
        } else if (op == '+') {
            sum += rn;
        } else if (op == '-') {
            sum -= rn;
        }
    }
    if (sum == 0)
        v[ans++] = s;
}

void dfs(int x, string s) {
    if (x > n) {
        cal(s);
        return;
    }
    char c;
    c = char(x + '0');
    dfs(x+1, s+'+'+c);
    dfs(x+1, s+' '+c);
    dfs(x+1, s+'-'+c);
}

int main() {
    cin >> n;
    ans = 0;
    dfs(2, "1");
    sort(v, v + ans);
    for (int i = 0; i < ans; i++)
        cout << v[i] << endl;
    return 0;
}
