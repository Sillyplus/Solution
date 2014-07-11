#include <iostream>
#include <cstdlib>


#define LL long long

using namespace std;

const int MN = 35;

long long f[MN] = {0};

long long cal(long long x) {
    long long rt = 0;
    for (int i = 31; i >= 0; i--) {
        if (x >= (1LL << i)) {
            x -= (1LL << i);
            rt += f[i];
            if (x > 0) rt += i-1;
        }
    }
    return rt;
}

int main() {
    long long x, y;
    cin >> x >> y;
    f[1] = f[0] = 0;
    for (int i = 2; i <= 31; i++)
        f[i] = f[i-1] + (1LL << (i-1)) - 1;
    cout << llabs(cal(x) - cal(y)) << endl;
    return 0;
}
