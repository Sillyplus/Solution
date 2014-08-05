#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>

using namespace std;

const int MN = 110;
const int INF = 1000000000;

int n;
int f[MN];
set<string> st;


int main() {
    string s, x;
    cin >> s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        st.insert(x);
    }
    for (int i = 0; i < MN; i++) f[i] = INF;
    int l = s.length();
    f[0] = 0;
    for(int i = 1; i <= l; i++) {
        for (int j = 0; j < i; j++)
            if (f[j] != INF) {
                x = "";
                for (int k = j; k < i; k++)
                    x += s[k];
                if (st.find(x) != st.end())
                    f[i] = min(f[i], f[j]+1);
        }
    }
    cout << f[l] << endl;
    return 0;
}
