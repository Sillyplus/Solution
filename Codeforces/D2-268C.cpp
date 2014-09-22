#include <iostream>

using namespace std;

int n;

int main() {
    cin >> n;
    if (n < 4) {
        cout << "NO" << endl;
    } else if ((n % 2) == 0) {
        cout << "YES" << endl;
        cout << "1 * 2 = 2" << endl;
        cout << "2 * 3 = 6" << endl;
        cout << "4 * 6 = 24" << endl;
        for (int i = 5; i <= n; i++)
            if ((i % 2) == 0) {
                cout << i << " - " << i-1 << " = 1" << endl;
            }
        for (int i = 0; i < (n-4)/2; i++)
            cout << 24 << " * 1 = 24" << endl;
    } else {
        cout << "YES" << endl;
        cout << "5 - 1 = 4" << endl;
        cout << "4 - 2 = 2" << endl;
        cout << "3 * 4 = 12" << endl;
        cout << "2 * 12 = 24" << endl;
        for (int i = 6; i < n; i++)
            if ((i % 2) == 0) {
                cout << i+1 << " - " << i << " = 1" << endl;
            }
        for (int i = 0; i < (n-5)/2; i++)
            cout << 24 << " * 1 = 24" << endl;
    }
    return 0;
}
