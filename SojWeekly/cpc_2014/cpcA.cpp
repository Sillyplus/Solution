#include <iostream>
using namespace std;

int gcd(int a, int b){
    return b == 0? a : gcd(b, a % b);
}

int main() {
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        int flag = 0;
        for (int j = 2; j*j < x; j++)
            if (x % j == 0) {
                if (gcd(j, x / j) == 1) {
                    flag = 1;
                }
            }
        if (!flag) cout << "NO\n";
            else cout << "YES\n";
    }
    return 0;
}
