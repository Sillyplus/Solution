#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    long long x, k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        k = sqrt(2*(x-1));
        if ((k*(k+1)) == (2*(x-1))) cout << 1 << ' ';
        else cout << "0" << " ";
    }
    return 0;
}
