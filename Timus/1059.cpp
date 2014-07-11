#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    cout << 0 << endl;
    for (int i = 0; i < n; i++) {
        cout << 'X' << endl << '*' << endl << i+1 << endl << '+' << endl;
    }
}
