#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct xy{
    int x, y;
} a[110];

int main(){
    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++){
        memset(a, 0, sizeof(a));
        int ans = 2147283647;
        cin >> n;
        for (int j = 0; j < n; j++){
            cin >> a[j].x >> a[j]. y;
        }
        int tmp;
        for (int j = 0; j < n-1; j++)
            for (int k = j+1; k < n; k++) {
                tmp = abs(a[j].x - a[k].x) + abs(a[j].y - a[k].y);
                ans = min(ans, tmp);
            }
        cout << ans << endl;
    }
    return 0;
}
