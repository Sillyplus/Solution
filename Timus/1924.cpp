#include <iostream>

using namespace std;

int main() {
    int n, ans = 0;;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (i % 2)
            ans += i;
        else
            ans -= i;
    }
    if (ans % 2)
        cout << "grimy" << endl;
    else
        cout << "black" << endl;
    return 0;
}
