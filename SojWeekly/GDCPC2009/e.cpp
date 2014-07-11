#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

const int MN = 110;

struct vv{
    string s;
    int ans;
};

char c[MN][MN];
string s[MN];
set<string> st;
set<string>::iterator its;
int f[MN] = {0};
vector<vv> v;
int a[MN];

bool comp(const vv &a, const vv &b) {
    if (a.ans != b.ans) return a.ans > b.ans;
    else return a.s < b.s;
}

bool cp(const int &a, const int &b) {
    if (a != b) return a > b;
    else return a > b;
}

int main() {
    int n;
    cin >> n;
    while (n) {
        for (int i = 0; i < n; i++) {
            cin >> s[i];
            st.insert(s[i]);
        }
        int x = st.size();
        memset(f, 0, sizeof(f));
        for (int i = 0; i < n; i++) cin >> c[i];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (c[i][j] == '1') f[j]++;
            }
        for (its = st.begin(); its != st.end(); its++) {
            vv vx;
            vx.s = *its;
            vx.ans = 0;
            a[0] = 0;
            for (int i = 0; i < n; i++) {
                if (vx.s == s[i]) {
                    a[0]++;
                    a[a[0]] = f[i];
                }
            }
            sort(a+1, a+a[0]+1, cp);
            a[a[0]+1] = 0;
            for (int i = 1; i <= a[0]+1; i++)
                if (i > a[i]) {
                    vx.ans = i-1;
                    break;
                }

            v.push_back(vx);
        }
        sort(v.begin(), v.end(), comp);
        for (int i = 0; i < x; i++)
            cout << v[i].s << ' ' << v[i].ans << endl;
        cin >> n;
        cout << endl;
        st.clear();
        v.clear();
    }
    return 0;
}
