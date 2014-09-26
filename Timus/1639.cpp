#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> m >> n;
    if ((n*m % 2) == 1) {
        cout << "[second]=:]\n";
    } else {
        cout << "[:=[first]\n";
    }
    return 0;
}
