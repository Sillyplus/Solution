#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
#include <string>

using namespace std;

const int MN = 10010;

struct st{
    int t, l;
    string s;
};

bool comp(const st &a, const st &b){
    if (a.t != b.t) return a.t < b.t;
    else return a.s < b.s;
}

st a[MN];

int main() {
    int n, t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i].t >> a[i].s >> a[i].l;
        sort(a, a+n, comp);
        int time = 0;
        for (int i = 0; i < n; i++) {
            if (a[i].t > time) {
                cout << a[i].s << " went out at time " << a[i].t << endl;
                time = a[i].t + a[i].l;
            } else {
                cout << a[i].s << " went out at time " << time << endl;
                time += a[i].l;
            }
        }
        cout << endl;
    }
    return 0;
}
