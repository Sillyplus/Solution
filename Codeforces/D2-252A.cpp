#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

const int MN = 1000010;

int n, v;
int a[100] = {0};
int f[100] = {0};

int main() {
    cin >> n >> v;
    int k, x;
    int count = 0;
    for (int i = 0; i < n; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> x;
            if (v > x) f[i]++;
        }
        if (f[i]) count += 1;
    }
    if (count) {
        cout << count << endl;
        for (int i = 0; i < n; i++)
            if (f[i])
                cout << i+1 << ' ';
    } else cout << count;
    cout << endl;
    return 0;
}
