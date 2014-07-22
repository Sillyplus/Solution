#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int ten[4] = {1, 10, 100, 1000};
const int maxl = 1000;

struct BigNumber{
    int d[maxl];
    BigNumber(string s) {
        int len = s.size();
        d[0] = (len-1)/4+1;
        int i, j, k;
        for (i = 1; i < maxl; i++) d[i] = 0;
        for (i = len-1; i >= 0; i--) {
            j = (len-1-i)/4+1;
            k = (len-1-i)%4;
            d[j] += ten[k] * (s[i] - '0');
        }
        while (d[0] > 1 && d[d[0]] == 0) d[0]--;
    }
    BigNumber() {
        *this = BigNumber(string("0"));
    }
    string toString() {
        string s("");
        int i, j, temp;
        for (i = 3; i >= 1; i--)
            if (d[d[0]] >= ten[i]) break;
        temp = d[d[0]];
        for (j = i; j >= 0; j--) {
            s = s + (char)(temp/ten[j]+'0');
            temp %= ten[j];
        }
        for (i = d[0]-1; i > 0; i--) {
            temp = d[i];
            for (j = 3; j >= 0; j--) {
                s = s + (char)(temp/ten[j]+'0');
                temp %= ten[j];
            }
        }
        return s;
    }
};

BigNumber operator * (const BigNumber &a, const BigNumber &b) {
    BigNumber c;
    c.d[0] = a.d[0] + b.d[0];
    int i, j, x;
    for (i = 1; i <= a.d[0]; i++) {
        x = 0;
        for (j = 1; j <= b.d[0]; j++) {
            x = a.d[i] * b.d[j] + x + c.d[i+j-1];
            c.d[i+j-1] = x % 10000;
            x /= 10000;
        }
        c.d[i+b.d[0]] = x;
    }
    while ((c.d[0] > 1) && (c.d[c.d[0]] == 0))
        c.d[0]--;
    return c;
}

string x, y;

int main() {
    cin >> x;
    cin >> y;
    BigNumber a(x), b(y);
    BigNumber c = a * b;
    cout << c.toString() << endl;
    return 0;
}
