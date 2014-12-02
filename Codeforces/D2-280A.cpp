#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 10010;

int main() {
    int n, sum = 0, tmp = 0;
    cin >> n;
    for (int i = 1; ; i++) {
        tmp += i;
        sum += tmp;
        if (sum > n) {
            cout << i-1 << endl;
            return 0;
        }
    }
    return 0;
}
