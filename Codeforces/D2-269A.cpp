#include <iostream>

using namespace std;

int a[10];

int main() {
    int k;
    bool flag2, flag4;
    flag2 = flag4 = false;
    for (int i = 0; i < 6; i++) {
        cin >> k;
        a[k]++;
    }
    for (int i = 1; i < 10; i++) {
        if (a[i] == 6) {
            flag2 = flag4 = true;
        }
        if (a[i] == 5) {
            flag2 = false;
            flag4 = true;
        }
        if (a[i] == 4) {
            flag4 = true;
        }
        if (a[i] == 2) {
            flag2 = true;
        }
    }
    if (flag4) {
        if (flag2)
            cout << "Elephant" << endl;
        else
            cout << "Bear" << endl;
    } else {
        cout << "Alien" << endl;
    }
    return 0;
}
