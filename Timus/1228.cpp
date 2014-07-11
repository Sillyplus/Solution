#include <iostream>

using namespace std;

int main() {
    int n, s, k;
    cin >> n >> s;
    for (int i = 0; i < n-1; i++) {
        cin >> k;
        cout << s/k - 1 << " ";
        s = k;
    }
    cin >> k;
    cout << s/k -1 << endl;;
    return 0;
}
