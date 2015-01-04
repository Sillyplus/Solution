/*******************************************************************************
	> File Name: 1563.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Sun Jan  4 12:20:14 2015
 ******************************************************************************/

#include <iostream>
#include <string>
#include <set>

using namespace std;

set<string> st;

int main() {
    string s;
    int n, ans = 0;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        if (st.find(s) != st.end())
            ans++;
        else 
        st.insert(s);
    }
    cout << ans << endl;
    return 0;
}
