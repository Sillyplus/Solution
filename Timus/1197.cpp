#include <iostream>

using namespace std;

int dx[10] = {-2,-1, 1, 2, 2, 1,-1,-2};
int dy[10] = { 1, 2, 2, 1,-1,-2,-2,-1};

int main() {
    int n, ans;
    char c[3];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c;
        ans = 0;
        for (int j = 0; j < 8; j++) {
            if ((c[0]+dx[j] >= 'a')&&(c[0]+dx[j] <= 'h')&&(c[1]+dy[j] >= '1')&&(c[1]+dy[j] <= '8'))
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
