#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

set<int> s1;
set<int> s2;
int n, k;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        s1.insert(k);
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        if (s1.find(k) != s1.end())
            s2.insert(k);
    }
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        if (s2.find(k) != s2.end())
            ans++;
    }
    cout << ans << endl;
    return 0;
}
