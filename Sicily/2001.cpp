#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <set>

using namespace std;

vector<int> p;
vector<int> q;
set<pair<int, int> > s;

int main() {
    int P, Q;
    cin >> P >> Q;
    p.clear();
    q.clear();
    for (int i = 1; i <= sqrt(P); i++)
        if (P % i == 0) {
            p.push_back(i);
            p.push_back(P / i);
        }
    for (int i = 1; i <= sqrt(Q); i++)
        if (Q % i == 0) {
            q.push_back(i);
            q.push_back(Q / i);
        }
    sort(p.begin(), p.end());
    sort(q.begin(), q.end());
    for (int i = 0; i < p.size(); i++)
        for (int j = 0; j < q.size(); j++) {
            s.insert(make_pair(p[i], q[j]));
        }
    set<pair<int, int> >::iterator its;
    for (its = s.begin(); its != s.end(); its++)
        printf("%d %d\n", (*its).first, (*its).second);
    return 0;
}
