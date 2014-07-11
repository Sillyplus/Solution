#include <iostream>
#include <cstdio>

using namespace std;

const int MN = 1010;

int a[MN] = {0};

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int sum = 0;
    int k = 1;
    for (int i = 1; i < n-1; i++) {
        int temp = a[i-1]+a[i]+a[i+1];
        if (sum < temp) {
            sum = temp;
            k = i;
        }
    }
    cout << sum << " " << k+1 << endl;
    return 0;
}
