#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int n, m;
bool a[1010];

int main() {
    cin >> n;
    int k, x;
    memset(a, false, sizeof(a));
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> x;
        a[x] = true;
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> x;
        a[x] = true;
    }
    for (int i = 1; i <= n; i++)
        if (!a[i]) {
            cout << "Oh, my keyboard!" << endl;
            return 0;
        }
    cout << "I become the guy." << endl;
    return 0;
}
