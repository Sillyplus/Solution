#include <iostream>
#include <algorithm>

using namespace std;

int a[10] = {0, 10, 670, 55252, 4816030};

int main() {
    int n;
    cin >> n;
    cout << a[n/2] << endl;
    return 0;
}

/*
int f[10100] = {0};

int ds(int x) {
    int t = 0;
    while (x) {
        t += x%10;
        x /= 10;
    }
    return t;
}

int main() {
    for (int i = 0; i < 10000; i++) f[i] = ds(i);
    sort(f, f+10000);
    int x = 1, t = 0;
    for (int i = 1; i < 10000; i++) {
        if (f[i] != f[i-1]) {
            t += x*x;
            x = 1;
        } else x++;
    }
    t += x*x;
    cout << t << endl;
    return 0;
}
*/
