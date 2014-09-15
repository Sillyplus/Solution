#include <iostream>
#include <cstring>

using namespace std;

int a[10];

int main() {
    int n, t;
    cin >> t;
    while (t--) {
        cin >> n;
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= n; i++) {
            int k = i;
            while (k) {
                a[k%10]++;
                k /= 10;
            }
        }
        cout << a[0];
        for (int i = 1; i <= 9; i++)
            cout << ' ' << a[i];
        cout << endl;
    }
    return 0;
}
