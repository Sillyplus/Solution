#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

const int MN = 1010;

int n, m, k;
set<string> st;
char c[MN];

int main() {
    string s, ss;
    cin.getline(c, MN);
    s = string(c);
    int i = 1;
    ss = "";
    while (i < (s.length()-1)) {
        if (s[i] == ' ') {
            i++;
        } else if (s[i] != ',') {
            ss += s[i];
            i++;
        } else if (s[i] == ','){
            st.insert(ss);
            ss = "";
            i += 2;
        }
    }
    if (ss.length() > 0)
        st.insert(ss);
    cout << st.size() << endl;
    return 0;
}
