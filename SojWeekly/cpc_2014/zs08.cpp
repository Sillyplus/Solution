#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>

using namespace std;

set<int> s;
set<int>::iterator it;
set<int> ss;
set<int>::iterator its;
int main() {
    int n, m, k;
    while (cin >> n) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> k;
            s.insert(k);
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> k;
            ss.insert(k);
        }
        for (its = ss.begin(); its != ss.end(); its++) {
            it = s.find(*its);
            if (it == s.end()) ans++;
        }
        cout << ans << endl;
        s.clear();
        ss.clear();
    }
    return 0;
}
