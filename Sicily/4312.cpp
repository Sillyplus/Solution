#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

string a, b;
int c[20];

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        memset(c, 0, sizeof(c));
        int l = min(a.size(), b.size());
        for (int i = 0; i < l; i++) {
            int x = a[i] - '0';
            int y = b[i] - '0';
            c[i] += (x+y);
            c[i+1] += (c[i] / 10);
            c[i] %= 10;
        }
        string tmp;
        if (l < a.size())
            tmp = a;
        else
            tmp = b;
        for ( ; l < tmp.size(); l++) {
            int x = tmp[l] - '0';
            c[l] += x;
            c[l+1] += (c[l] / 10);
            c[l] %= 10;
        }
        while (c[l] == 0) l--;
        for (int i = l; i >= 0; i--)
            cout << c[i];
        cout << endl;
    }
    return 0;
}
