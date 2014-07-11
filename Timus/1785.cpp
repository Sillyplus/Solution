#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n < 5) {
        cout << "few\n";
    } else if (n < 10) {
        cout << "several\n";
    } else if (n < 20) {
        cout << "pack\n";
    } else if (n < 50) {
        cout << "lots\n";
    } else if (n < 100) {
        cout << "horde\n";
    } else if (n < 250) {
        cout << "throng\n";
    } else if (n < 500) {
        cout << "swarm\n";
    } else if (n < 1000) {
        cout << "zounds\n";
    } else cout << "legion\n";
    return 0;
}
