#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>

using namespace std;

const int MN = 60;

int p, q, l, r;
set<int> v1;
set<int> v2;
set<int>::iterator its;

int main() {
    cin >> p >> q >> l >> r;
    int a, b;
    for (int i = 0; i < p; i++) {
        cin >> a >> b;
        for (int j = a; j <= b; j++)
            v1.insert(j);
    }
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        for (int j = a; j <= b; j++)
            v2.insert(j);
    }
    int ans = 0;
    for (int i = l; i <= r; i++) {
        for (its = v2.begin(); its != v2.end(); its++) {
            if (v1.find((*its)+i) != v1.end()) {
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
