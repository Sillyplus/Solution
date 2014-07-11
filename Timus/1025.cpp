#include <iostream>
#include <algorithm>

using namespace std;

int a[110] = {0};

int main() {
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
    sort(a, a+k);
    int ans = 0;
    for (int i = 0; i < (k+1)/2; i++) {
        ans += (a[i]+1)/2;
    }
    cout << ans << endl;
    return 0;
}
