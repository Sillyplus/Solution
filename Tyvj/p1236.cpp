#include <iostream>

using namespace std;

int n, ans;

int main() {
    cin >> n;
    ans = 0;
    for (int i = 3; i <= n; i++)
        for (int j = 0; j < 20; j++)
            if ((i & (1 << j)) && (i & (1 << (j+1))))
                ans++;
    cout << ans << endl;
    return 0;
}
