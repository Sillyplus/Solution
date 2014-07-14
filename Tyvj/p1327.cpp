#include <iostream>

using namespace std;

char c[5][5];
int ans;

int main() {
    ans = 0;
    for (int i = 0;i < 4; i++)
        cin >> c[i];
    for (int i = 0; i < 4; i++) {
        for (int j = i+1; j < 4; j++) {
            if (c[0][i] > c[0][j]) ans++;
            if (c[i][0] > c[j][0]) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
