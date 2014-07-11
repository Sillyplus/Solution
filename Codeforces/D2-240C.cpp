#include <iostream>
#include <cstring>
#include <map>

using namespace std;

const int MN = 1000000010;

map<int, int> mp;

int main() {
    int n, k;
    cin >> n >> k;
    if (n == 1){
        if (k) {
            cout << -1 << endl;
        } else {
            cout << 1 << endl;
        }
        return 0;
    }
    if ((n/2) > k){
        cout << -1 << endl;
        return 0;
    }
    int tmp;
    int tt = 2;
    tmp = k - (n - 2)/2;
    cout << tmp << ' ' << 2 * tmp << ' ';
    mp[tmp] = 1;
    mp[2*tmp] = 1;
    int cur = 1;
    for (int i = 0; i < (n-2)/2; i++) {
        if (mp.count(cur) == 0 && mp.count(cur+1) == 0) {
            cout << cur << ' ' << cur+1 << ' ';
            tt += 2;
            cur += 2;
        } else {
            i--;
            cur += 2;
        }
    }
    if (tt < n) {
        while (mp.count(cur) != 0) cur++;
        cout << cur;
    }
    return 0;
}
