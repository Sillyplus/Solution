#include <iostream>
#include <cmath>

using namespace std;

int n;

bool isprime(int x) {
    for (int i = 2; i <= sqrt(x); i++)
        if (x % i == 0) return false;
    return true;
}

int get(int x) {
    if (x < 4) return 1;
    if (x % 2 == 0) return 2;
    if (isprime(x)) return 1;
    if (isprime(x-2)) return 2;
    return 3;
}

int main() {
    cin >> n;
    int x, y;
    while (n--) {
        cin >> x >> y;
        int flag = 0;
        if (x > y) {
            if (get(x) <= get(y)) flag = 1;
        } else {
            if (get(y) > get(x)) flag = 1;
        }
        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
