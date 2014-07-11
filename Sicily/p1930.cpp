#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int main() {
    int t, n, x;
    cin >> t;
    while (t--) {
        cin >> n;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> x;
            v.push_back(x);
        }
        for (int i = 0; i < v.size()-1; i++) {
            int tmp = i;
            for (int j = i + 1; j < v.size(); j++) {
                if (v[tmp] > v[j]) {
                    tmp  = j;
                    ans ++;
                }
            }
            if (tmp != i) {
                x = v[tmp];
                v[tmp] = v[i];
                v[i] = x;
            }
        }
        cout << ans << endl;
        v.clear();
    }
    return 0;
}
