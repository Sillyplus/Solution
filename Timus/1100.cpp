#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector< vector<int> > a;
vector<int> v;

int main() {
    int n, x, y;
    v.clear();
    cin >> n;
    for (int i = 0; i < 104; i++) a.push_back(v);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x, &y);
        a[y].push_back(x);
    }
    vector<int>::iterator its;
    for (int i = 100; i >= 0; i--) {
        if (!a[i].empty()) {
            for (its = a[i].begin(); its != a[i].end(); its++)
            cout << *its << ' ' << i << endl;
        }
    }
    return 0;
}
