#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct tt{
    int id, s;
};

bool comp(const tt &a, const tt &b) {
    return a.s > b.s;
}

vector<tt> v;

int main() {
    int c;
    cin >> c;
    int p, n;
    tt k;
    while (c--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> k.id >> k.s >> p;
            v.push_back(k);
        }
        sort(v.begin(), v.end(), comp);
        for (int i= 0; i < n-1; i++) {
            cout << v[i].id << ' ';
        }
        cout << v[n-1].id << endl;
        v.clear();
    }
    return 0;
}
