#include <iostream>
#include <string>

using namespace std;

const int MN = 1500;

int n, m;
int f[MN];

int main() {
    cin >> n >> m;
    string s;
    int l, r, k;
    for (int i = 1; i <= m; i++) {
        cin >> s >> l >> r >> k;
        for (int j = l; j<= r; j++)
            f[j] -= k;
    }
    for (int i = 1; i <= 1440; i++)
        if (f[i]+n+1 <= 0) {
            cout << "Runtime Error" << endl;
            cout << i << endl;
            return 0;
        } else {
            n += (f[i]+1);
        }
    cout << "Accepted" << endl;
    cout << n << endl;;
    return 0;
}
