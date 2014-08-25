#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

typedef long long LL;

using namespace std;

const int MN = 1e9;

LL a, b, c;
vector<LL> v;

LL gets(LL x) {
    LL ret = 0;
    while (x) {
        ret += x%10;
        x /= 10;
    }
    return ret;
}

int main() {
    cin >> a >> b >> c;
    for (LL i = 1; i <= 81; i++) {
        LL x = b * (LL)(pow(i*1.0, a*1.0)+0.5) + c;
        if (x > 0 && x < MN) {
            if (gets(x) == i)
                v.push_back(x);
        }
    }
    sort(v.begin(), v.end());
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << ' ';
    return 0;
}
