#include <iostream>

using namespace std;

char c[1010];

int main() {
    int l, n, m;
    cin >> l;
    while (l--) {
        cin >> n >> m;
        cin >> c;
        for (int i = 0; i < n; i++) {
            for (int j = i*m; j < i*m+m; j++)
                cout << c[j];
            cout << endl;
        }
    }
    return 0;
}
