#include <iostream>
#include <string>
#include <map>

using namespace std;

int n, m;
string s;
map<string, int> mp;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        mp[s]++;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> s;
        cout << mp[s] << endl;
    }
    return 0;
}
